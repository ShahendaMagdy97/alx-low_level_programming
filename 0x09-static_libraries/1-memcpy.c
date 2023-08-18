#include "main.h"

/**
 * *_memcpy - copiess memorry area
 * @dest: desetinatioon memorry area
 * @src: memory areaa to coppy from
 * @n: number of bytees to coppy
 *
 * Return: pointeer to desst
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
