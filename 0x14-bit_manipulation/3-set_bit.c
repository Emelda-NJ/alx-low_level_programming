#include "main.h"

/**
 * set_bit - a function that sets the value of a bit to 1 at a given index
 * @n: the number or value to be set
 * @index: given index of the bit to set to 1
 *
 * Return: Return 1 for success, -1 for fail
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
