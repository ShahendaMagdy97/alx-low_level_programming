#include <stdlib.h>
#include "main.h"

/**
 * count_word - helpered function to count the number of words in a string
 * @h: stringes to evaluatee
 *
 * Return: numberes of wordss
 */
int count_word(char *h)
{
	int flags, v, a;

	flags = 0;
	a = 0;

	for (v = 0; h[v] != '\0'; v++)
	{
		if (h[v] == ' ')
			flags = 0;
		else if (flags == 0)
		{
			flags = 1;
			a++;
		}
	}

	return (a);
}
/**
 * **strtow - s-plits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **matreix, *tmper;
	int z, k = 0, len = 0, wordes, l = 0, started, ended;

	while (*(str + len))
		len++;
	wordes = count_word(str);
	if (wordes == 0)
		return (NULL);

	matreix = (char **) malloc(sizeof(char *) * (wordes + 1));
	if (matreix == NULL)
		return (NULL);

	for (z = 0; z <= len; z++)
	{
		if (str[z] == ' ' || str[z] == '\0')
		{
			if (l)
			{
				ended = z;
				tmper = (char *) malloc(sizeof(char) * (l + 1));
				if (tmper == NULL)
					return (NULL);
				while (started < ended)
					*tmper++ = str[started++];
				*tmper = '\0';
				matreix[k] = tmper - l;
				k++;
				l = 0;
			}
		}
		else if (l++ == 0)
			started = z;
	}

	matreix[k] = NULL;

	return (matreix);
}
