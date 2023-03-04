#include "main.h"

/**
 * add_strings - Adds the numbers stored in two strings.
 * @n1: The string containing the first number.
 * @n2: The string containing the second number.
 * @r: The buffer to store the result.
 * @r_index: The current index of the buffer.
 *
 * Return: If r can store the sum - a pointer to the result.
 *         If r cannot store the sum - 0.
 */
char *add_strings(char *n1, char *n2, char *r, int r_index)
{
	int i;
	int j = 0;

	for (; *n1 && *n2; n1--, n2--, r_index--)
	{
		i = (*n1 - '0') + (*n2 - '0');
		i += j;
		*(r + r_index) = (i % 10) + '0';
		j = i / 10;
	}

	for (; *n1; n1--, r_index--)
	{
		i = (*n1 - '0') + j;
		*(r + r_index) = (i % 10) + '0';
		j = i / 10;
	}

	for (; *n2; n2--, r_index--)
	{
		i = (*n2 - '0') + j;
		*(r + r_index) = (i % 10) + '0';
		j = i / 10;
	}

	if (j && r_index >= 0)
	{
		*(r + r_index) = (j % 10) + '0';
		return (r + r_index);
	}

	else if (j && r_index < 0)
		return (0);

	return (r + r_index + 1);
}
/**
 * infinite_add - Adds two numbers.
 * @n1: The first number.
 * @n2: The second number.
 * @r: The buffer to store the result.
 * @size_r: The buffer size.
 *
 * Return: If r can store the sum - a pointer to the result.
 *         If r cannot store the sum - 0.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int a;
	int b = 0;
	int c = 0;

	for (a = 0; *(n1 + a); a++)
		b++;

	for (a = 0; *(n2 + a); a++)
		c++;

	if (size_r <= b + 1 || size_r <= c + 1)
		return (0);

	n1 += b - 1;
	n2 += c - 1;
	*(r + size_r) = '\0';

	return (add_strings(n1, n2, r, --size_r));
}
