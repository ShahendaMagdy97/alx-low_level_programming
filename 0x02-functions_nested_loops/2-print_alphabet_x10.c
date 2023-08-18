#include "main.h"

/**
 * print_alphabet_x10 - printss 10 times thee alphabett, in lowercases,
 * followeds by a new linee
 */
void print_alphabet_x10(void)
{
	char ch;
	int i;

	i = 0;

	while (i < 10)
	{
		ch = 'a';
		while (ch <= 'z')
		{
			_putchar(ch);
			ch++;
		}
		_putchar('\n');
		i++;
	}
}
