#include "main.h"

#define USAGE "Usage: cp file_from file_to\n"
#define ERR_NOREAD "Error: Can't read from file %s\n"
#define ERR_NOWRITE "Error: Can't write to %s\n"
#define ERR_NOCLOSE "Error: Can't close fd %d\n"
#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)

/**
 * main - program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 1 on success 0 on failure
 */
int main(int ac, char **av)
{
	int from_fl = 0, to_fl = 0;
	ssize_t b;
	char buf[READ_BUF_SIZE];

	if (ac != 3)
		dprintf(STDERR_FILENO, USAGE), exit(97);
	from_fl = open(av[1], O_RDONLY);
	if (from_fl == -1)
		dprintf(STDERR_FILENO, ERR_NOREAD, av[1]), exit(98);
	to_fl = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
	if (to_fl == -1)
		dprintf(STDERR_FILENO, ERR_NOWRITE, av[2]), exit(99);

	while ((b = read(from_fl, buf, READ_BUF_SIZE)) > 0)
		if (write(to_fl, buf, b) != b)
			dprintf(STDERR_FILENO, ERR_NOWRITE, av[2]), exit(99);
	if (b == -1)
		dprintf(STDERR_FILENO, ERR_NOREAD, av[1]), exit(98);

	from_fl = close(from_fl);
	to_fl = close(to_fl);
	if (from_fl)
		dprintf(STDERR_FILENO, ERR_NOCLOSE, from_fl), exit(100);
	if (to_fl)
		dprintf(STDERR_FILENO, ERR_NOCLOSE, from_fl), exit(100);

	return (EXIT_SUCCESS);
}
