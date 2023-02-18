#include <stdio.h>

/**
* main - This is the entry point to a program.
*
* Return: returns the value 0 to mean successful.
*/


int main(void)
{
	int i;

	for (i = 0 ; i < 10 ; i++)
		putchar(i + '0');
	putchar('\n');
	return (0);
}
