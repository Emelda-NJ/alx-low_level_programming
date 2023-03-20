#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - Frees dogs or memory.
 * @d: The dog to be freed or pointer to dog_t.
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->owner);
	free(d->name);
	free(d);
}
