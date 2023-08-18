#include "main.h"
/**
 * wildcmp - returns 1 after comparing two strings
 * If the strings are thought to be identical,
 * if not, return 0.
 * @s1: the standard string
 * @s2: the unique string that contains "*"
 *
 * Return: 1 if identical, 0 else
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '\0' && *s1 == '\0')
		return (1);

	if (*s2 == '*' && *(s2 + 1) != '\0' && *s1 == '\0')
		return (0);

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));

	return (0);
}
