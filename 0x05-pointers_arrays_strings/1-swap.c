#include "main.h"

/**
 * swap_int - swap the values of two integers
 *
 * @a: integer to swap
 * @b: integer to swap
 *
 * Return: Nothing
*/

void swap_int(int *a, int *b)

{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
