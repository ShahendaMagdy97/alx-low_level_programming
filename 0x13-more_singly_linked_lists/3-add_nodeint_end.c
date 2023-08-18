#include "lists.h"

/**
 * add_nodeint_end - ends a linked list with an additional node
 * @head: pointer to the list's top element
 * @n: information to add to the new element
 *
 * Return: the new node's reference, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *temps = *head;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (temps->next)
		temps = temps->next;

	temps->next = new;

	return (new);
}
