#include "main.h"
#include <stdio.h>

/**
 * print_buffer - Prints a buffer 10 bytes at a time, starting with
 *                the byte position, then showing the hex content,
 *                then displaying printable charcaters.
 * @b: The buffer to be printed.
 * @size: The number of bytes to be printed from the buffer.
 */
void print_buffer(char *b, int size)
{
	int a;
	int i;

	for (a = 0; a < size; a += 10)
	{
		printf("%08x: ", a);

		for (i = 0; i < 10; i++)
		{
			if ((i + a) >= size)
				printf("  ");

			else
				printf("%02x", *(b + i + a));

			if ((i % 2) != 0 && i != 0)
				printf(" ");
		}

		for (i = 0; i < 10; i++)
		{
			if ((i + a) >= size)
				break;

			else if (*(b + i + a) >= 31 &&
				 *(b + i + a) <= 126)
				printf("%c", *(b + i + a));

			else
				printf(".");
		}

		if (a >= size)
			continue;

		printf("\n");
	}

	if (size <= 0)
		printf("\n");
}
