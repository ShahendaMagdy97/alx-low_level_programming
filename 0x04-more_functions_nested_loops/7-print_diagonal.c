#include "main.h"

/**
 * print_diagonal - Draws a diagonal lines according parameter
 *
 * @n: is the number of times charachter \ should be printed
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
			for (y = 1; y <= n; y++)
			{
				if (y == x)
				_putchar('\\');
				else if (y < x)
			_putchar(' ');
			}
			_putchar('\n');
		}
	}
}
