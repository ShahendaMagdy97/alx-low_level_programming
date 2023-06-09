#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

int _putchar(char c);
int _strlen(char *sl);
size_t print_list(const list_t *fp);
size_t list_len(const list_t *fp);
list_t *add_node(list_t **padd, const char *strn);
list_t *add_node_end(list_t **padd, const char *strn);
void free_list(list_t *hp);
void _constructor(void) __attribute__ ((constructor));

#endif
