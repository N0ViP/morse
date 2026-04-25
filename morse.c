#include <stdio.h>
#include "morse.h"


void	help(void)
{
	// TODO

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
