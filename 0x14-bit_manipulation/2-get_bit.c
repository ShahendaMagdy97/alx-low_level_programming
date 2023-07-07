#include "main.h"

/**
 * get_bit - gets the bit at the index
 * @i: the number to index
 * @index: the bit to get
 *
 * Return: the bit state or -1 on error
 */
int get_bit(unsigned long int i, unsigned int index)
{
	if (index >= sizeof(i) * 8)
		return (-1);

	return (i >> index & 1);
}
