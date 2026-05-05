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
	if (is_morse_char((unsigned char)*str))
	{
		printf("%s", morse_table[(unsigned char)*str]);
		str++;
	}
	while (*str)
	{
		if (is_morse_char((unsigned char)*str))
		{
			printf(" %s", morse_table[(unsigned char)*str]);
		}
		str++;
	}
	printf("\n");
}

void decode(char *str)
{
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
