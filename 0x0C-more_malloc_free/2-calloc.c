#include "main.h"
#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array of a certain number
 *           of elements, using malloc.
 * @nmemb: The number of elements.
 * @size: The byte size of each array element.
 *
 * Return: If nmemb = 0, size = 0, or the function fails - NULL.
 *         Otherwise - a pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *cal;
	char *p;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	cal = malloc(size * nmemb);

	if (cal == NULL)
		return (NULL);

	p = cal;

	for (i = 0; i < (size * nmemb); i++)
		p[i] = '\0';

	return (cal);
}
