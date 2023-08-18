#include "main.h"

/**
 * _puts_recursion - prints a string after which a new line is added.
 * @s: to print a string
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}
	_putchar(*s);
	_puts_recursion(s + 1);
}
