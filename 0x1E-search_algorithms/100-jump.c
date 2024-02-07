#include "search_algos.h"
#include <math.h>

/**
 * jump_search - looks for a value in a list of
 * utilizing the Jump search method, integers
 * @array: array of input
 * @size:dimension of the array
 * @value: a good place to look
 * Return: index of the number
 */
int jump_search(int *array, size_t size, int value)
{
int index, n, t, drev;

if (array == NULL || size == 0)
return (-1);

n = (int)sqrt((double)size);
t = 0;
drev = index = 0;

do {
printf("Value checked array[%d] = [%d]\n", index, array[index]);

if (array[index] == value)
return (index);
t++;
drev = index;
index = t *n;
} while (index < (int)size && array[index] < value);

printf("Value found between indexes [%d] and [%d]\n", drev, index);

while (drev <= index && drev < (int)size)
{
printf("Value checked array[%d] = [%d]\n", drev, array[drev]);
if (array[drev] == value)
return (drev);
drev++;
}

return (-1);
}
