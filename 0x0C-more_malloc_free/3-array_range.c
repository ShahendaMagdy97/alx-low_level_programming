#include <stdlib.h>
#include "main.h"

/**
 * *array_range - produces a collection of integers
 * @min: least storageable range of values
 * @max: maximum value range and element count stored
 *
 * Return: identifier for the fresh array
 */
int *array_range(int min, int max)
{
	int *per;
	int x, sizo;

	if (min > max)
		return (NULL);

	sizo = max - min + 1;

	per = malloc(sizeof(int) * sizo);

	if (per == NULL)
		return (NULL);

	for (x = 0; min <= max; x++)
		per[x] = min++;

	return (per);
}

