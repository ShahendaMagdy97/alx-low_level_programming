#include "search_algos.h"

/**
 * mocurze_search - looks for a value in a list of
 * utilizing the binary search technique, integers
 *
 * @array: multiple inputs
 * @size:dimension of the array
 * @value: An excellent spot to look
 * Return: index of the number
 */
int mocurze_search(int *array, size_t size, int value)
{
size_t flaz = size / 2;
size_t z = 0;

if (array == NULL || size == 0)
return (-1);

printf("Searching in array");

while (z < size)
{
printf("%s %d", (z == 0) ? ":" : ",", array[z]);
z++;
}

printf("\n");

if (flaz && size % 2 == 0)
flaz--;

if (value == array[flaz])
return ((int)flaz);

if (value < array[flaz])
return (mocurze_search(array, flaz, value));

flaz++;

return (mocurze_search(array + flaz, size - flaz, value) + flaz);
}

/**
 * binary_search - calls to binary_search to return
 * the index of the number
 *
 * @array: array of input
 * @size:dimension of the array
 * @value: a good place to look
 * Return: index of the number
 */
int binary_search(int *array, size_t size, int value)
{
int index;

index = mocurze_search(array, size, value);

if (index >= 0 && array[index] != value)
return (-1);

return (index);
}
