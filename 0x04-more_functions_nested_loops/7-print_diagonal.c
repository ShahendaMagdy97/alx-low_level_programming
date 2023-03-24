#include "main.h"

/**
 * print_diagonal - Draws a diagonal lines according parameter
 *
 * @n: is the number of times the to print diagonal lines
 * Return: empty
*/

void print_diagonal(int n)
{
	int x, y;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (x = 1; x <= n; x++)
		{
			for (y = 1; y <= x; y++)
			{
				_putchar(32);
			}
			_putchar(92);
			_putchar('\n');
		}
	}
}
