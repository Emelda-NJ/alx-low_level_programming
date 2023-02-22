#include "main.h"

/**
* print_alphabet - prints the alphabet in lowercase, followed by a new line
*
* Return: returns the value 0 to mean successful
*/

void print_alphabet(void)
{
	char i;

	for (i = 'a'; i <= 'z'; i++)
		_putchar(i);

	_putchar('\n');
}