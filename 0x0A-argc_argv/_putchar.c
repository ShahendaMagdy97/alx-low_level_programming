#include <unistd.h>

/**
 * _putchar - stdout is updated with the character C
 * @c: The text to be printed
 *
 * Return: About achievement 1.
 * On error, -Errno is set properly and 1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

