#include "main.h"

/**
 * _strlen - returns the length of a string
 * @sl: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *sl)
{
	int x = 0;

	if (!sl)
		return (0);

	while (*sl++)
		x++;
	return (x);
}

/**
 * create_file - creates a file
 * @filename: name of file to create
 * @text_content: text to write
 *
 * Return: 1 on success 0 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fl;
	ssize_t byte = 0, lon = _strlen(text_content);

	if (!filename)
		return (-1);
	fl = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fl == -1)
		return (-1);
	if (lon)
		byte = write(fl, text_content, lon);
	close(fl);
	return (byte == lon ? 1 : -1);
}
