#include "lists.h"

/**
 * free_list - frees all nodes of a list
 * @hp: pointer to head node
 *
 * Return: void
 */
void free_list(list_t *hp)
{
	list_t *node, *next_node;

	if (!hp)
		return;

	node = hp;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
}
