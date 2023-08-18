#include "lists.h"
/**
 * print_listint_safe -function that securely prints linkedlist inside of loop
 * @head: pointer to the linked list's first node
 * Return: new_node
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tm_n = NULL;
	const listint_t *y_n = NULL;
	size_t coun = 0;
	size_t new_n;

	tm_n = head;
	while (tm_n)
	{
		printf("[%p] %d\n", (void *)tm_n, tm_n->n);
		coun++;
		tm_n = tm_n->next;
		y_n = head;
		new_n = 0;
		while (new_n < coun)
		{
			if (tm_n == y_n)
			{
				printf("-> [%p] %d\n", (void *)tm_n, tm_n->n);
				return (coun);
			}
			y_n = y_n->next;
			new_n++;
		}
		if (!head)
			exit(98);
	}
	return (coun);
}
