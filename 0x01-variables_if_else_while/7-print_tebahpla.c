#include <stdio.h>

/**
* main - This is the entry point to a program.
*
* Return: returns the value 0 to mean successful
*/


int main(void)
{
	char i;

	for (i = 'z' ; i >= 'a' ; i--)
		putchar(i);
	putchar('\n');
	return (0);
}
