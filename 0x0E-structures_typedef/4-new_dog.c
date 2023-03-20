#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - Creates a new dog.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 *
 * Return: The new struct dog.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	unsigned int n, o, i;
	dog_t *my_dog;

	if (name == NULL || age < 0 || owner == NULL)
		return (NULL);

	my_dog = malloc(sizeof(dog_t));
	if (my_dog == NULL)
		return (NULL);

	for (n = 0; name[n]; n++)
		;
	n++;
	my_dog->name = malloc(n * sizeof(char));
	if (my_dog->name == NULL)
	{
		free(my_dog);
		return (NULL);
	}

	for (i = 0; i < n; i++)
		my_dog->name[i] = name[i];
	my_dog->age = age;

	for (o = 0; owner[o]; o++)
		;
	o++;
	my_dog->owner = malloc(o * sizeof(char));
	if (my_dog->owner == NULL)
	{
		free(my_dog->name);
		free(my_dog);
		return (NULL);
	}

	for (i = 0; i < o; i++)
		my_dog->owner[i] = owner[i];
	return (my_dog);
}
