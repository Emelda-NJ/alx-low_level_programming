#include "main.h"
#include <stdlib.h>

/**
 * word - Locates the index marking the end of the
 *            first word contained within a string.
 * @str: The string to be searched.
 *
 * Return: The index marking the end of the initial word pointed to by str.
 */
int word(char *str)
{
	int i = 0, j = 0;

	while (*(str + i) && *(str + i) != ' ')
	{
		j++;
		i++;
	}

	return (j);
}

/**
 * count_words - Counts the number of words contained within a string.
 * @str: The string to be searched.
 *
 * Return: The number of words contained within str.
 */
int count_words(char *str)
{
	int i = 0, w = 0, j = 0;

	for (i = 0; *(str + i); i++)
		j++;

	for (i = 0; i < j; i++)
	{
		if (*(str + i) != ' ')
		{
			w++;
			i += word(str + i);
		}
	}

	return (w);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to be split.
 *
 * Return: If str = NULL, str = "", or the function fails - NULL.
 *         Otherwise - a pointer to an array of strings (words).
 */
char **strtow(char *str)
{
	char **s;
	int i = 0, w, a, b, l;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	w = count_words(str);
	if (w == 0)
		return (NULL);

	s = malloc(sizeof(char *) * (w + 1));
	if (s == NULL)
		return (NULL);

	for (a = 0; a < w; a++)
	{
		while (str[i] == ' ')
			i++;

		b = word(str + i);

		s[a] = malloc(sizeof(char) * (b + 1));

		if (s[a] == NULL)
		{
			for (; a >= 0; a--)
				free(s[a]);

			free(s);
			return (NULL);
		}

		for (l = 0; l < b; l++)
			s[a][l] = str[i++];

		s[a][l] = '\0';
	}
	s[a] = NULL;

	return (s);
}
