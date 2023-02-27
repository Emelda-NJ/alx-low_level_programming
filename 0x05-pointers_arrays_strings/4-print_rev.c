#include "main.h"

/**
 * print_rev - It prints a string in reverse.
 * @s: The string to be printed.
 */
void print_rev(char *s)
{
	int str = 0;

	while (s[str] != '\0')
		str++;

	for (str -= 1; str >= 0; str--)
		_putchar(s[str]);

	_putchar('\n');
}
