#include "lists.h"

/**
 * delete_nodeint_at_index -removes a node at a specific index in a linked list
 * @head: pointer to the list's top element
 * @index: index of the deleted node
 *
 * Return: One (Success) or one (Failure)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temps = *head;
	listint_t *curr = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temps);
		return (1);
	}

	while (i < index - 1)
	{
		if (!temps || !(temps->next))
			return (-1);
		temps = temps->next;
		i++;
	}


	curr = temps->next;
	temps->next = curr->next;
	free(curr);

	return (1);
}
