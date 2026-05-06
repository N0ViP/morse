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
	// TODO

	return ;
}

void encode(const char *str)
{
	unsigned char	c;

	do
	{
		c = *str;
		if (is_morse_char(c))
		{
			if (islower(c))
				c = toupper(c);
			printf(" %s", morse_table[c]);
		}
	} while (*str++);
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
	if (ac == 1 || ac > 3 || (ac == 2 && !strcmp(av[1], "-h")))
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
