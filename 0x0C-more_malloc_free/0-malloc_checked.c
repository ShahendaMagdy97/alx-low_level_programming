#include <stdlib.h>
#include "main.h"

/**
 * *malloc_checked - malloc is used to allocate memory
 * @b: number of allocated bytes
 *
 * Return: a reference to the memory space allotted
 */
void *malloc_checked(unsigned int b)
{
	void *pter;

	pter = malloc(b);

	if (pter == NULL)
		exit(98);

	return (pter);
}
