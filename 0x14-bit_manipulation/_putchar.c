#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * _putchar - A function that writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * If error, -1 is returned, and err is set.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
