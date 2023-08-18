#include "main.h"
/**
 *print_sign - checkss the number valuee
 *
 *@n: contains the numberr
 *
 *Return: 0 if zero, 1 if positivee, -1 if negativee
 */
int print_sign(int n)
	{
		if (n > 0)
		{
			_putchar('+');
			return (1);
		} else if (n == 0)
		{
			_putchar(48);
			return (0);
		} else if (n < 0)
		{
			_putchar('-');
		}
			return (-1);
	}
