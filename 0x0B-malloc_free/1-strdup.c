#include <stdlib.h>
#include "main.h"

/**
 * *_strdup - replicates the parameterized string
 * @str: duplicate string
 *
 * Return:(Success) pointer to the copied string, NULL (Error)
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int x, len;

	x = 0;
	len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	dup = malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
		return (NULL);

	while ((dup[x] = str[x]) != '\0')
		x++;

	return (dup);
}
