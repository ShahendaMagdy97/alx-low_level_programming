#include "main.h"

int actual_prime(int n, int i);

/**
 * is_prime_number - determines whether a number is a prime number or not
 * @n: number to evaluate
 *
 * Return: 0 if n is not a prime number, 1 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (actual_prime(n, n - 1));
}

/**
 * actual_prime - determines a number's primeness recursively
 * @n: number to be assessed
 * @i: iterator
 *
 * Return: 1 if n is prime, 0 if not
 */
int actual_prime(int n, int i)
{
	if (i == 1)
		return (1);
	if (n % i == 0 && i > 0)
		return (0);
	return (actual_prime(n, i - 1));
}

