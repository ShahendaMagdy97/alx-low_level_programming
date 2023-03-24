#include "main.h"

/**
 * print_diagonal - Draws a diagonal lines according parameter
 *
 * @n: is the number of times the to print diagonal lines
 * Return: empty
*/

void print_diagonal(int n)
{
	int postn, space;

	if (n <= 0)
		_putchar('\n');
	else
	{
		for (postn = 1; postn <= n; postn++)
		{
			for (space = 1; space <= postn; space++)
				_putchar(' ');
			_putchar(92); /*is equal to '/' char*/
			_putchar('\n');
		}
	}
}
