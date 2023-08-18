#include "lists.h"

/**
 * pop_listint - removes the linked list's head node
 * @head: pointer to the linked list's top-level element
 *
 * Return: the removed data included within the elements,
 * or 0 if there is no such list
 */
int pop_listint(listint_t **head)
{
	listint_t *temps;
	int numb;

	if (!head || !*head)
		return (0);

	numb = (*head)->n;
	temps = (*head)->next;
	free(*head);
	*head = temps;

	return (numb);
}
