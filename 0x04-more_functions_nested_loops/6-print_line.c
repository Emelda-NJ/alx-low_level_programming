#include "main.h"

/**
 * print_line - This draws a straight line using the character _.
 * @n: This is number of _ characters to be printed.
 */
void print_line(int n)
{
	int i;

	if (n > 0)
	{
		for (i = 0; i < n; i++)
			_putchar('_');
	}

	_putchar('\n');
}
