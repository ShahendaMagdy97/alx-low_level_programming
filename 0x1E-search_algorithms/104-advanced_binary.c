#include "search_algos.h"

/**
 * bis_search - searches a list of values for a value
 * utilizing the binary search technique, integers
 *
 * @array: multiple inputs
 * @size: width of the array
 * @value: An excellent spot to look
 * Return: the number's index
 */
int bis_search(int *array, size_t size, int value)
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
{
if (flaz > 0)
return (bis_search(array, flaz + 1, value));
return ((int)flaz);
}

if (value < array[flaz])
return (bis_search(array, flaz + 1, value));

flaz++;
return (bis_search(array + flaz, size - flaz, value) + flaz);
}


/**
 * advanced_binary - using bis_search calls to return
 * the number's index
 * @array: multiple inputs
 * @size: width of the array
 * @value: a good place to look
 * Return: the number's index
 */
int advanced_binary(int *array, size_t size, int value)
{
int index;

index = bis_search(array, size, value);

if (index >= 0 && array[index] != value)
return (-1);

return (index);
}
