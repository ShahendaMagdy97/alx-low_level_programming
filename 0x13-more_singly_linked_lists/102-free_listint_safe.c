#include "lists.h"

/**
 * free_listint_safe - sets a linked list free
 * @h: pointer to the connected list's root node
 *
 * Return: elements in the freed list number
 */
size_t free_listint_safe(listint_t **h)
{
	size_t lens = 0;
	int difef;
	listint_t *temps;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		difef = *h - (*h)->next;
		if (difef > 0)
		{
			temps = (*h)->next;
			free(*h);
			*h = temps;
			lens++;
		}
		else
		{
			free(*h);
			*h = NULL;
			lens++;
			break;
		}
	}

	*h = NULL;

	return (lens);
}
