#include "main.h"

/**
 * binary_to_uint - A function to converts a binary number to an unsigned int.
 * @b: A pointer to a string containing binary numbers of 0 and 1 chars.
 *
 * Return: If b is NULL or contains chars not 0 or 1 - 0.
 *         Otherwise - the unsigned int.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num1 = 0, num2 = 1;
	int len;

	if (b == '\0')
		return (0);

	for (len = 0; b[len];)
		len++;

	for (len -= 1; len >= 0; len--)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);

		num1 += (b[len] - '0') * num2;
		num2 *= 2;
	}

	return (num1);
}
