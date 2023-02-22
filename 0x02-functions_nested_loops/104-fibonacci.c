#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers, starting with
 *        1 and 2, separated by a comma followed by a space.
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;
	unsigned long j = 0, k = 1, sum;
	unsigned long j_a1, j_a2, k_a1, k_a2;
	unsigned long a1, a2;

	for (i = 0; i < 92; i++)
	{
		sum = j + k;
		printf("%lu, ", sum);

		j = k;
		k = sum;
	}

	j_a1 = j / 10000000000;
	k_a1 = k / 10000000000;
	j_a2 = j % 10000000000;
	k_a2 = k % 10000000000;

	for (i = 93; i < 99; i++)
	{
		a1 = j_a1 + k_a1;
		a2 = j_a2 + k_a2;
		if (j_a2 + k_a2 > 9999999999)
		{
			a1 += 1;
			a2 %= 10000000000;
		}

		printf("%lu%lu", a1, a2);
		if (i != 98)
			printf(", ");

		j_a1 = k_a1;
		j_a2 = k_a2;
		k_a1 = a1;
		k_a2 = a2;
	}
	printf("\n");
	return (0);
}
