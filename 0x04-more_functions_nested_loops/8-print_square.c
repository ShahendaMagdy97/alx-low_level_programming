#include "main.h"

/**
 * print_square - print a square using the character #
 *
 * @size: is the size of the square
 *
 * Return: Always 0 (success)
*/

void print_square(int size)
{
	int row, coloum;

	for (row = 1; row <= size; row++)
	{
		for (coloum = 1; coloum <= size; coloum++)
			_putchar('#');
		_putchar('\n');
	}
}
