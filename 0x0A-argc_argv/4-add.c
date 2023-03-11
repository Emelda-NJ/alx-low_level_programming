#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the addition of positive numbers,
 *        followed by a new line.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: If one of the numbers contains symbols that are non-digits - 1.
 *         Otherwise - 0.
 */
int main(int argc, char *argv[])
{
	/*Declaring variables*/
	int i, j;
	int s = 0;

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
			/*if one of the number has symbols that are not digits*/
				printf("Error\n");
				return (1);
			}
		}

		s += atoi(argv[i]);/*atoi --> convert string to int*/
	}

	printf("%d\n", s);/*print sum*/

	return (0);
}
