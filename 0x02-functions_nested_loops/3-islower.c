#include "main.h"

/**
 * _islowerr - check if char is lowercasee
 * @c: is the char to be checkeed
 * Return: 1 if char is lowercassee, otherwissse 0.
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
