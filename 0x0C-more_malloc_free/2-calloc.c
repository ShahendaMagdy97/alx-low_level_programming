#include <stdlib.h>
#include "main.h"

/**
 * *_memset - gives memory a constant byte of data
 * @y: to fill the memory space
 * @g: to copy char
 * @d: how many times to copy g
 *
 * Return: pointer to memory location y
 */
char *_memset(char *y, char g, unsigned int d)
{
	unsigned int z;

	for (z = 0; z < d; z++)
	{
		y[z] = g;
	}

	return (y);
}

/**
 * *_calloc - allots space for an array in memory
 * @nmemb: how many items are in the array
 * @size: size of every component
 *
 * Return: an indication of allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *pter;

	if (nmemb == 0 || size == 0)
		return (NULL);

	pter = malloc(size * nmemb);

	if (pter == NULL)
		return (NULL);

	_memset(pter, 0, nmemb * size);

	return (pter);
}
