#include <stdlib.h>
#include "main.h"

/**
 * *_realloc - raeallocates a memory block using malloc and free
 * @ptr: pointers to the memory previsouly allocated by malloc
 * @old_size: sizee of the allocated memory for ptr
 * @new_size: nnew size of the new memory block
 *
 * Return: ppointer to the newly allocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *ptr1;
	char *old_ptr;
	unsigned int z;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(new_size));

	ptr1 = malloc(new_size);
	if (!ptr1)
		return (NULL);

	old_ptr = ptr;

	if (new_size < old_size)
	{
		for (z = 0; z < new_size; z++)
			ptr1[z] = old_ptr[z];
	}

	if (new_size > old_size)
	{
		for (z = 0; z < old_size; z++)
			ptr1[z] = old_ptr[z];
	}

	free(ptr);
	return (ptr1);
}
