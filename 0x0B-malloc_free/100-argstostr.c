#include "main.h"
#include <stdlib.h>
/**
  *argstostr - combines all of the program's arguments.
  *@ac: argument weight.
  *@av: array pointer with size ac.
  *Return: NULL if either av or ac equals zero,a new string's pointer.
  *NULL on fail.
  */
char *argstostr(int ac, char **av)
{
	int x, n, y, siz;
	char *arg;

	siz = 0;
	y = 0;
	if (ac == 0 || av == NULL)
		return (NULL);
	x = 0;
	while (x < ac)
	{
		n = 0;
		while (av[x][n])
		{
			siz++;
			n++;
		}
		siz++;
		x++;
	}
	arg = malloc((sizeof(char) * siz) + 1);
	if (arg == NULL)
		return (NULL);
	x = 0;
	while (x < ac)
	{
		n = 0;
		while (av[x][n])
		{
			arg[y] = av[x][n];
			n++;
			y++;
		}
		arg[y] = '\n';
		y++;
		x++;
	}
	arg[y] = '\0';
	return (arg);
}
