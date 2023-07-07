#include "main.h"

/**
 * clear_bit - clears the bit at the index
 * @i: the number to index
 * @index: the bit to clear
 *
 * Return: 1 if successful, -1 on error
 */
int clear_bit(unsigned long int *i, unsigned int index)
{
	if (index >= sizeof(i) * 8)
		return (-1);

	if (*i & 1L << index)
		*i ^= 1L << index;
	return (1);
}
