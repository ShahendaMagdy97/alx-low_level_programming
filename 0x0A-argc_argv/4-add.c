#include <stdio.h>
#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int z, d, n, len, f, digit;

	z = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (z < len && f == 0)
	{
		if (s[z] == '-')
			++d;

		if (s[z] >= '0' && s[z] <= '9')
		{
			digit = s[z] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[z + 1] < '0' || s[z + 1] > '9')
				break;
			f = 0;
		}
		z++;
	}

	if (f == 0)
		return (0);

	return (n);
}

/**
 * main - adds two positive number
 * @argc: number of arguments
 * @argv: array of arguents
 *
 * Return: 0 (Success), or 1 (Success)
 */
int main(int argc, char *argv[])
{
	int sum, nume, i, j, k;

	sum = 0;

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
			{
				puts("Error");
				return (1);
			}
		}
	}

	for (k = 1; k < argc; k++)
	{
		nume = _atoi(argv[k]);
		if (nume >= 0)
		{
			sum += nume;
		}
	}

	printf("%d\n", sum);
	return (0);
}
