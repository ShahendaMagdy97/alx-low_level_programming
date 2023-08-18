#include "lists.h"

/**
 * insert_nodeint_at_index - a new node is added to a linked list,
 * at a specific location
 * @head: reference to the list's root node
 * @idx: index where the new node is added, or index
 * @n: data information to add to the new node
 *
 * Return: the new node's pointer, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int z;
	listint_t *new;
	listint_t *temps = *head;

	new = malloc(sizeof(listint_t));
	if (!new || !head)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	for (z = 0; temps && z < idx; z++)
	{
		if (z == idx - 1)
		{
			new->next = temps->next;
			temps->next = new;
			return (new);
		}
		else
			temps = temps->next;
	}

	return (NULL);
}
