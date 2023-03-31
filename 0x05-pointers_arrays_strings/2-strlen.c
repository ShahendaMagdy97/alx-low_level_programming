#include "main.h"

/**
 * _Strlen - returns the lengh of a string
 *
 * @s: char to check
 *
 * Return: 0
*/

int _strlen(char *s)
{
	int i = 0;

	while (s[i])
	i++;

	return (i);
}
