#include <stdio.h>
#include "main.h"

/**
 * main - prints the program's name
 * @argc: various arguments
 * @argv: multiple arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);

	return (0);
}
