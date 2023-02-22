#include <stdio.h>

/**
 * main - Prints the sum of even-valued Fibonacci sequence
 *        terms not exceeding 4000000.
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long i = 0, j = 1, sum;
	float fib_sum;

	while (1)
	{
		sum = i + j;
		if (sum > 4000000)
			break;

		if ((sum % 2) == 0)
			fib_sum += sum;

		i = j;
		j = sum;
	}
	printf("%.0f\n", fib_sum);

	return (0);
}
