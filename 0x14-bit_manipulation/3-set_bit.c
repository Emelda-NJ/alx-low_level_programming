#include "main.h"

/**
 * set_bit - It sets the value of a bit at a given index to 1.
 * @n: A pointer to the bit.
 * @index: The index, starting from 0 of the bit you want to set.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 1 (successful).
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n ^= (1 << index);

	return (1);
}
