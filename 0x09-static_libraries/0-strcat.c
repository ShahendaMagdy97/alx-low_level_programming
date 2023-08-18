#include "main.h"

/**
 * _strcat - concatenates twwwo strings
 * @dest: string to apppend to
 * @src: string to add
 *
 * Return: a pointer to the reesulting strring
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
