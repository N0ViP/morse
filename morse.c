#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "morse.h"

int is_morse_char(int c)
{
    if (isalnum(c))
        return (1);
    if (c == '.' || c == ',' || c == '?' || c == '\'' ||
        c == '!' || c == '/' || c == '(' || c == ')' ||
        c == '&' || c == ':' || c == ';' || c == '=' ||
        c == '+' || c == '-' || c == '_' || c == '"' ||
        c == '$' || c == '@' || c == ' ')
        return (1);
    return (0);
}

void	help(void)
{
	printf("Usage: morse [OPTION] STRING\n");
	printf("\n");
	printf("Options:\n");
	printf("  -e    encode STRING into Morse code\n");
	printf("  -d    decode Morse code STRING into text\n");
	printf("  -h    show this help message\n");
	printf("\n");
	printf("Notes:\n");
	printf("  - Use spaces to separate Morse symbols.\n");
	printf("  - Use '/' to separate words in Morse.\n");

	return ;
}

void sound_effect(const char *code)
{
	while (*code)
	{
		if (*code == '.')
		{
			system("paplay dot.wav");
		}
		else if (*code == '-')
		{
			system("paplay dash.wav");
		}
		usleep(UNIT);
		code++;
	}
}

void encode(const char *str)
{
	unsigned char	c;

	while (*str)
	{
		c = *str;
		if (is_morse_char(c))
		{
			if (islower(c))
				c = toupper(c);
			printf(" %s", morse_table[c]);
			fflush(stdout);
			sound_effect(morse_table[c]);
			usleep(UNIT * 2);
		}
		str++;
	}
	usleep(UNIT * 2);
	printf("\n");

	return ;
}

void decode(const char *str)
{
	char *code;

	for (int i = 0, j, k; str[i]; )
	{
		while (isspace(str[i]) && str[i])
			i++;

		if (!str[i])
			break ;

		for (j = 0; !isspace(str[i + j]) && str[i + j]; j++)
			;

		code = malloc(j + 1);
		if (!code)
			exit (1);

		code = memcpy(code, str + i, j);
		code[j] = '\0';

		for (k = 0; k < 128; k++)
		{
			if (morse_table[k] && !strcmp(code, morse_table[k]))
			{
				printf("%c", k);
				break ;
			}
		}
		if (k >= 128)
		{
			printf("#");
		}

		i += j;
		free(code);
	}

	return ;
}

int main(int ac, char *av[])
{
	if (ac == 2 && !strcmp(av[1], "-h"))
	{
		help();
		return (0);
	}
	if (ac == 1 || ac > 3)
	{
		dprintf(2, HINTMSG);
		return (0);
	}

	if (!strcmp(av[1], "-e"))
	{
		encode(av[2]);
	}
	else if (!strcmp(av[1], "-d"))
	{
		decode(av[2]);
	}
	else
	{
		dprintf(2, ERRMSG);
		return (1);
	}

	return (0);
}
