#include "main.h"

/**
 * set_bit - sets the bit at the index
 * @i: the number to index
 * @index: the bit to set
 *
 * Return: 1 if successful, -1 on error
 */
int set_bit(unsigned long int *i, unsigned int index)
{
	if (index >= sizeof(i) * 8)
		return (-1);

	return (!!(*i |= 1L << index));
}
