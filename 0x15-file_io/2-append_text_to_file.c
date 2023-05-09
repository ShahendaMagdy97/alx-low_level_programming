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
 * append_text_to_file - appends text to a file
 * @filename: name of file to create
 * @text_content: text to write
 *
 * Return: 1 on success 0 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fl;
	ssize_t byte = 0, lon = _strlen(text_content);

	if (!filename)
		return (-1);
	fl = open(filename, O_WRONLY | O_APPEND);
	if (fl == -1)
		return (-1);
	if (lon)
		byte = write(fl, text_content, lon);
	close(fl);
	return (byte == lon ? 1 : -1);
}
