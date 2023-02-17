#include <stdio.h>
#include <unistd.h>


/**
 * main - The main() function is the entry point.
 *
 * Return: terminates main() function and returns 1 to mean successful
 */

int main(void)

{
	write(2, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n", 59);
	return (1);
}
