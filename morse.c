#include <stdio.h>
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

void encode(char *str)
{
	unsigned char	c;

	c = *str;
	if (is_morse_char(c))
	{
		if (islower(c))
			c = toupper(c);
		printf("%s", morse_table[c]);
		str++;
	}
	while (*str)
	{
		c = *str;
		if (is_morse_char(c))
		{
			if (islower(c))
				c = toupper(c);
			printf(" %s", morse_table[c]);
		}
		str++;
	}
	printf("\n");

	return ;
}

void decode(char *str)
{
	for (int i = 0, j; str[i]; i++)
	{
		for (j = 0; str[i + j] == ' ' || str[i + j]; j++)
			;

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
