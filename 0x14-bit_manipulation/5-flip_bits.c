#include "main.h"

/**
 * flip_bits - return number of bits that would need to be flipped to
 * transform one number to another
 *
 * @x: first number
 * @y: second number
 *
 * Return: number of bits to flip to convert numbers
 */
unsigned int flip_bits(unsigned long int x, unsigned long int y)
{
	unsigned long int exorval = x ^ y;
	unsigned int total = 0;

	while (exorval)
	{
		if (exorval & 1ul)
			total++;
		exorval = exorval >> 1;
	}
	return (total);
}
