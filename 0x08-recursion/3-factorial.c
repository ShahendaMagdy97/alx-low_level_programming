#include "main.h"

/**
 * factorial - returns a number's factorial
 * @n: number to provide the factorial back from
 *
 * Return: factorial of n
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	return (n * factorial(n - 1));
}
