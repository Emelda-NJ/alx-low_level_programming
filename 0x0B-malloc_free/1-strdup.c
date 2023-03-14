#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _strdup - Returns a pointer to a newly-allocated space in memory
 *           containing a copy of the string given as parameter.
 *           returns a pointer to the duplicated string.
 * @str: The character to be copied.
 *
 * Return: If str == NULL or insufficient memory is available - NULL.
 *         Otherwise - a pointer to the duplicated string.
 */
char *_strdup(char *str)
{
	char *duple;
	int i, j = 0;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		j++;

	duple = malloc(sizeof(char) * (j + 1));

	if (duple == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		duple[i] = str[i];

	duple[j] = '\0';

	return (duple);
}
