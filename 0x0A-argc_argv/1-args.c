#include "main.h"
#include <stdio.h>

/**
 * main - Prints the number of arguments passed to the program.
 * @argc: The number of arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0 (successful).
 */
int main(int argc, char __attribute__((__unused__)) *argv[])
{
	printf("%d\n", argc - 1);

	return (0);
}
