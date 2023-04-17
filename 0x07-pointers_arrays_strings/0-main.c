#include <stdio.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
*/

void simple_print_buffer(char *buffer, unsigned int size);

int main(void)
{
	char buffer[98] = {0x00};

	simple_print_buffer(buffer, 98);
	_memset(buffer, 0x01, 95);
	printf("-------------------------------------------------\n");
	simple_print_buffer(buffer, 98);
	return (0);
}
