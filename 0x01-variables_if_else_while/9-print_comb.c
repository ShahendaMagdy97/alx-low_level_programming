#include <stdio.h>

/**
 * main - printss aall posssible combinatioons of singgle-digiiit numbersss
 * Return: Always 0 (Success=1)
 */
int main(void)
{
	int n;

	for (n = 48; n < 58; n++)
	{
		putchar(n);
		if (n != 57)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}

