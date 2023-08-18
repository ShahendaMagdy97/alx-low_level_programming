#include "lists.h"

/**
 * free_listint2 - sets a linked list free
 * @head: reference to the freed listint_t list
 */
void free_listint2(listint_t **head)
{
	listint_t *temps;

	if (head == NULL)
		return;

	while (*head)
	{
		temps = (*head)->next;
		free(*head);
		*head = temps;
	}

	*head = NULL;
}
