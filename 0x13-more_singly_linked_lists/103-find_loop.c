#include "lists.h"

/**
 * find_listint_loop - in a linked list locates the loop
 * @head: linked list to look up
 *
 * Return: address of the initial node in the loop, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slowed = head;
	listint_t *fasted = head;

	if (!head)
		return (NULL);

	while (slowed && fasted && fasted->next)
	{
		fasted = fasted->next->next;
		slowed = slowed->next;
		if (fasted == slowed)
		{
			slowed = head;
			while (slowed != fasted)
			{
				slowed = slowed->next;
				fasted = fasted->next;
			}
			return (fasted);
		}
	}

	return (NULL);
}
