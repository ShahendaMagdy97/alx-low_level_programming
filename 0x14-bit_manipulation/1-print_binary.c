#include "main.h"

/**
 * print_binary - prints a number as binary string
 * @p: the number to print
 *
 * Return: void
 */
void print_binary(unsigned long int p)
{
	int bit = sizeof(p) * 8, printed = 0;

	while (bit)
	{
		if (p & 1L << --bit)
		{
			_putchar('1');
			printed++;
		}
		else if (printed)
			_putchar('0');
	}
	if (!printed)
		_putchar('0');
}
