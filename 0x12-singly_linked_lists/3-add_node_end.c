#include "lists.h"

/**
 * add_node_end - adds a node to the end of the list
 * @padd: address of pointer to head node
 * @strn: str field of node
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **padd, const char *strn)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *node = *padd;

	if (!padd || !new_node)
		return (NULL);
	if (strn)
	{
		new_node->str = strdup(strn);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
		new_node->len = _strlen(new_node->str);
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*padd = new_node;
	return (new_node);
}
