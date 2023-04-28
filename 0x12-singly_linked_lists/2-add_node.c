#include "lists.h"

/**
 * add_node - adds a node to the start of the list
 * @padd: address of pointer to head node
 * @strn: str field of node
 *
 * Return: size of list
 */
list_t *add_node(list_t **padd, const char *strn)
{
	list_t *new_head = malloc(sizeof(list_t));

	if (!padd || !new_head)
		return (NULL);
	if (strn)
	{
		new_head->str = strdup(strn);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
		new_head->len = _strlen(new_head->str);
	}

	new_head->next = *padd;
	*padd = new_head;
	return (new_head);
}
