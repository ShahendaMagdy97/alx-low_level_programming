#include <stdio.h>

/**
 * main - entry point
 * Description: print numbers of base 10
 * Retturn: Always 0 (Success)
*/

int main(void)
{
	int n;

	for (n = 0; n <= 9; n++)
	{
		printf("%d", n);
	}
	printf("\n");
	return (0);
}
