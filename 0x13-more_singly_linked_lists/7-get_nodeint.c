#include "lists.h"

/**
 * get_nodeint_at_index -retrieves the node in a linked list at specific index
 * @head: initial node of a linked list
 * @index: index the node's return index
 *
 * Return: pointer to the desired node, otherwise NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int z = 0;
	listint_t *temps = head;

	while (temps && z < index)
	{
		temps = temps->next;
		z++;
	}

	return (temps ? temps : NULL);
}
