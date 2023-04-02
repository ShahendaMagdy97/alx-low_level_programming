#include <stdio.h>

/**
 * main - entry point
 *
 * Description: print alphabet in lowercase then in uppercase
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	char n = 'a';
	char m = 'A';

	/*prints a - z*/
	while (n <= 'z')
	{
		putchar(n);
		ch++;
	}

	/*prints A - Z*/
	while (m <= 'Z')
	{
		putchar(m);
		ch++;
	}
	putchar('\n');

	return (0);
}
