#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates random valid passwords for the
 *        program 101-crackme.
 *
 * Return: Always 0.
 */
int main(void)
{
	char password[84];
	int i = 0;
	int sum = 0;
	int c_a1, c_a2;

	srand(time(0));

	while (sum < 2772)
	{
		password[i] = 33 + rand() % 94;
		sum += password[i++];
	}
	password[i] = '\0';

	if (sum != 2772)
	{
		c_a1 = (sum - 2772) / 2;
		c_a2 = (sum - 2772) / 2;
		if ((sum - 2772) % 2 != 0)
			c_a1++;

		for (i = 0; password[i]; i++)
		{
			if (password[i] >= (33 + c_a1))
			{
				password[i] -= c_a1;
				break;
			}
		}
		for (i = 0; password[i]; i++)
		{
			if (password[i] >= (33 + c_a2))
			{
				password[i] -= c_a2;
				break;
			}
		}
	}
printf("%s", password);
return (0);
}
