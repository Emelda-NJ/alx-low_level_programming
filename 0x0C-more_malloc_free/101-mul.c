#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _strlen - Finds the length of a string.
 * @str: The string to be measured.
 *
 * Return: The length of the string.
 */
int _strlen(char *str)
{
	int len = 0;

	while (*str++)
		len++;

	return (len);
}

/**
 * _puts - prints a string, followed by a new line,
 * @str: pointer to the string to print
 * Return: void
*/


void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}

}


/**
 * _atoi - Converts a string to a corresponding int.
 * @s: The string to be converted.
 *
 * Return: The converted int.
 */
int _atoi(const char *s)
{
	int mul = 1;
	unsigned long int r = 0, n, i;

	for (n = 0; !(s[n] >= 48 && s[n] <= 57); n++)
	{
		if (s[n] == '-')
		{
			mul *= -1;
		}
	}

	for (i = n; s[i] >= 48 && s[i] <= 57; i++)
	{
		r *= 10;
		r += (s[i] - 48);
	}

	return (mul * r);
}

/**
 * print_int - prints an integer.
 * @n: int
 * Return: 0
 */

void print_int(unsigned long int n)
{
	unsigned  long int i, j = 1, r;

	for (i = 0; n / j > 9; i++, j *= 10)
		;

	for (; j >= 1; n %= j, j /= 10)
	{
		r = n / j;
		_putchar('0' + r);
	}
}

/**
 * main - Multiplies two positive numbers.
 * @argv: The number of arguments passed to the program.
 * @argc: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char const *argv[])
{
	(void)argc;

	if (argc != 3)
	{
		_puts("Error ");
		return (0);
	}
	print_int(_atoi(argv[1]) * _atoi(argv[2]));
	_putchar('\n');

return (0);
}
