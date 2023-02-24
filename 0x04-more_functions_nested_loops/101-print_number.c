#include "main.h"

/**
 * print_number - This function prints an integer.
 * @n: This is the integer to be printed.
 */
void print_number(int n)
{
	unsigned int n1 = n;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n1;
	}

	if ((n1 / 10) > 0)
		print_number(n1 / 10);

	_putchar((n1 % 10) + '0');
}
