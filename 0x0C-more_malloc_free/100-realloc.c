#include "main.h"
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated.
 * @old_size: The size in bytes of the allocated space for ptr.
 * @new_size: The size in bytes of the new memory block.
 *
 * Return: If new_size == old_size - ptr.
 *         If new_size == 0 and ptr is not NULL - NULL.
 *         Otherwise - a pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *real;
	char *a, *b;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		real = malloc(new_size);

		if (real == NULL)
			return (NULL);

		return (real);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	a = ptr;
	real = malloc(sizeof(*a) * new_size);

	if (real == NULL)
	{
		free(ptr);
		return (NULL);
	}

	b = real;

	for (i = 0; i < old_size && i < new_size; i++)
		b[i] = *a++;

	free(ptr);
	return (real);
}
