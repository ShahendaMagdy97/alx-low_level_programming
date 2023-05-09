#include "main.h"

/**
 * read_textfile - reads text from a file and prints it
 * @filename: name of file to read
 * @letters: number of bytes to read
 *
 * Return: number bytes read/printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fl;
	ssize_t byte;
	char buf[READ_BUF_SIZE * 8];

	if (!filename || !letters)
		return (0);
	fl = open(filename, O_RDONLY);
	if (fl == -1)
		return (0);
	byte = read(fl, &buf[0], letters);
	byte = write(STDOUT_FILENO, &buf[0], byte);
	close(fl);
	return (byte);
}
