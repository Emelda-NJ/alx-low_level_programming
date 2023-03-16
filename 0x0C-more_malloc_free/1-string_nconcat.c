#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - Concatenates two strings
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of bytes of s2 to concatenate to s1.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - a pointer to the concatenated space in memory.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *string;
	unsigned int i, len = n;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i]; i++)
		len++;

	string = malloc(sizeof(char) * (len + 1));

	if (string == NULL)
		return (NULL);

	len = 0;

	for (i = 0; s1[i]; i++)
		string[len++] = s1[i];

	for (i = 0; s2[i] && i < n; i++)
		string[len++] = s2[i];

	string[len] = '\0';

	return (string);
}
