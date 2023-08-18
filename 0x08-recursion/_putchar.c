#include <unistd.h>

/**
 * _putchar - stdout is updated with the character C.
 * @c: The text to be printed
 *
 * Return: On success 1.
 * On error, -1 is sent back, and the proper errno value is set.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
