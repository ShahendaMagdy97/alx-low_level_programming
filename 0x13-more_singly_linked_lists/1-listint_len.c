#include "lists.h"

/**
 * listint_len - yields the size of a linked list's elements
 * @h: traversal of a linked list of type listint_t
 *
 * Return: amount of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		num++;
		h = h->next;
	}

	return (num);
}
