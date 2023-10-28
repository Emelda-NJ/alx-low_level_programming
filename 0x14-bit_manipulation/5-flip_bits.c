#include "main.h"

/**
 * flip_bits - a function that returns the number of bits you would
 *             need to flip to get from one number to another
 * @n: Stores the first number
 * @m: Stores the second number
 *
 * Return: Return the number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int c;
	unsigned long int b = n ^ m;

	for (i = 63; i >= 0; i--)
	{
	c = b >> i;
	if (c & 1)
	count++;
	}

	return (count);
}
