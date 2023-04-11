#include "main.h"

/**
 * flip_bits - Counts the number of bits to flip.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The necessary number of bits to flip to get from n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int i = n ^ m, bits = 0;

	while (i > 0)
	{
		bits += (i & 1);
		i >>= 1;
	}

	return (bits);
}
