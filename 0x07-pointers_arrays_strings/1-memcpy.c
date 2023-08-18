#include "main.h"

/**
 * *_memcpy - copies (memorys) area
 * @dest: destination (memorys) area
 * @src: memory area to copys from
 * @n: number of (bytes) to copys
 *
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
