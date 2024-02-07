#include "search_algos.h"

/**
 * linear_search - looks for a value in a list of
 * With the linear search technique, integers
 * @array: array of input
 * @size: dimension of the array
 * @value: a good place to look
 * Return: Always EXIT_SUCCESS
 */
int linear_search(int *array, size_t size, int value)
{
int z;

if (array == NULL)
return (-1);

for (z = 0; z < (int)size; z++)
{
printf("Value checked array[%u] = [%d]\n", z, array[z]);
if (value == array[z])
return (z);
}
return (-1);
}
