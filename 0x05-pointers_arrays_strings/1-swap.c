#include "main.h"

/**
 * swap_int - swap the values of two integers
 *
 * @a: int paramete 1
 * @b: int paramete 2
 *
 * Return: Nothing
*/

void swap_int(int *a, int *b);
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
