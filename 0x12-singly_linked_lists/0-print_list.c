#include "lists.h"

/**
 * _strlen - returns the length of a string
 * @sl: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *sl)
{
	int d = 0;

	if (!sl)
		return (0);
	while (*sl++)
		d++;
	return (d);
}

/**
 * print_list - prints a linked lists
 * @fp: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *fp)
{
	size_t d = 0;

	while (fp)
	{
		printf("[%d] %s\n", _strlen(fp->str), fp->str ? fp->str : "(nil)");
		fp = fp->next;
		d++;
	}
	return (d);
}
