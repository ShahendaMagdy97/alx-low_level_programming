#include "lists.h"

/**
 * list_len - determines length of linked list
 * @fp: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *fp)
{
	size_t d = 0;

	while (fp)
	{
		fp = fp->next;
		d++;
	}
	return (d);
}
