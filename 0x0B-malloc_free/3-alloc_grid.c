#include <stdlib.h>
#include "main.h"

/**
 * **alloc_grid - produces an array of integers in two dimensions
 * @width: the matrix's breadth
 * @height: the matrix's height
 *
 * Return: identifier for the generated matrix (Success)
 * or NULL (Error)
 */
int **alloc_grid(int width, int height)
{
	int **err;
	int y, z;

	if (height <= 0 || width <= 0)
		return (NULL);

	err = (int **) malloc(sizeof(int *) * height);

	if (err == NULL)
		return (NULL);

	for (y = 0; y < height; y++)
	{
		err[y] = (int *) malloc(sizeof(int) * width);
		if (err[y] == NULL)
		{
			free(err);
			for (z = 0; z <= y; z++)
				free(err[z]);
			return (NULL);
		}
	}

	for (y = 0; y < height; y++)
	{
		for (z = 0; z < width; z++)
		{
			err[y][z] = 0;
		}
	}
	return (err);
}
