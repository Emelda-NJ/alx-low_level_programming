#include "main.h"

/**
 * _strlen - It returns the length of a string.
 * @s: The string from which the length is gotten from.
 *
 * Return: The length of string.
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s++)
		length++;

	return (length);
}
