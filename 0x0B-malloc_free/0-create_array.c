#include "main.h"
#include <stdlib.h>

/**
 * create_array - Creates an array of chars and
 *                initializes it with a specific char.
 * @size: The size of the array.
 * @c: The specific char to intialize the array.
 *
 * Return: If size == 0 or the function fails - NULL.
 *         Otherwise - return a pointer to the array.
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0 || array == NULL)
		return (NULL);

	array = malloc(sizeof(char) * size);

	for (i = 0; i < size; i++)
		array[i] = c;

	return (array);
}
