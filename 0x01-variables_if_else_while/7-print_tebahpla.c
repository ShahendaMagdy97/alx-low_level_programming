#include <stdio.h>

/**
 * main - printss  the the lowercasee>> alphabeet in reversee,
 * followeed by by a neww linee
 * Return: Alwaysss >>0 >>(Successs)
 */
int main(void)
{
	char ch;

	for (ch = 'z'; ch >= 'a'; ch--)
	{
		putchar(ch);
	}
	putchar('\n');
	return (0);
}
