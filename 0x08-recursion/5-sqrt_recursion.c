#include "main.h"

int actual_sqrt_recursion(int n, int i);

/**
 * _sqrt_recursion - returns a number's natural square root
 * @n: number to get the square root of
 *
 * Return: the outcome's square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (actual_sqrt_recursion(n, 0));
}

/**
 * actual_sqrt_recursion - to find the natural state, recurse
 * square root of a number
 * @n: a number to use in computing the square root of
 * @i: iterator
 *
 * Return: the outcome's square root
 */
int actual_sqrt_recursion(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (actual_sqrt_recursion(n, i + 1));
}
