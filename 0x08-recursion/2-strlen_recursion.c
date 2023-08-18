#include "main.h"

/**
 * _strlen_recursion - returns a string's length
 * @s: using a string to determine its length
 *
 * Return: how long the string is
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}
