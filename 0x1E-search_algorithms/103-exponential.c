#include "search_algos.h"

/**
  * _tigary_search - finds a value in a sorted array
  *               binary search of integers.
  * @array: a pointer to the array's initial element in the search.
  * @left: the [sub]array's starting index for the search.
  * @right: the [sub]array's ending index, which is used to search.
  * @value: a value to look for.
  *
  * Return: If the value is absent array is NULL, the result is -1.
  *       If not, the value's index will be used.
  * Description: aft each modification pri [sub]array being searched.
  */
int _tigary_search(int *array, size_t left, size_t right, int value)
{
size_t z;

if (array == NULL)
return (-1);

for (; right >= left; )
{
printf("Searching in array: ");
for (z = left; z < right; z++)
printf("%d, ", array[z]);
printf("%d\n", array[z]);

z = left + (right - left) / 2;
if (array[z] == value)
return (z);
if (array[z] > value)
right = z - 1;
else
left = z + 1;
}

return (-1);
}


/**
  * exponential_search - finds a value in a sorted array
  *       utilizing exponential search, of integers.
  * @array: a pointer to the array's initial element in the search.
  * @size: the array's total number of elements.
  * @value: a value to look for.
  * Return: -1 is returned if value is absent or the array is NULL
  *    Unless otherwise specified, the value's index.
  * Description: prints a value each time the array is compared.
  */
int exponential_search(int *array, size_t size, int value)
{
size_t z = 0, right;

if (array == NULL)
return (-1);

if (array[0] != value)
{
for (z = 1; z < size && array[z] <= value; z = z * 2)
printf("Value checked array[%ld] = [%d]\n", z, array[z]);
}

right = z < size ? z : size - 1;
printf("Value found between indexes [%ld] and [%ld]\n", z / 2, right);
return (_tigary_search(array, z / 2, right, value));
}
