#include "lists.h"

/**
 * sum_listint - sums up all the information in a listint_t list
 * @head: initial node of a linked list
 *
 * Return: resultant amount
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temps = head;

	while (temps)
	{
		sum += temps->n;
		temps = temps->next;
	}

	return (sum);
}
