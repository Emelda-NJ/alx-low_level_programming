#include "main.h"

/**
 * strlen_no_wilds - Returns the length of a string,
 *                   ignoring wildcard characters.
 * @s: The string.
 *
 * Return: The length.
 */

int strlen_no_wilds(char *s)
{
	int l = 0;
	int i = 0;

	if (*(s + i))
	{
		if (*s != '*')
			l++;

		i++;
		l += strlen_no_wilds(s + i);
	}

	return (l);
}

/**
 * iterate_wilds - Iterates through a string located at a wildcard
 *                until it points to a non-wildcard character.
 * @ws: The string to be iterated through.
 */
void iterate_wilds(char **ws)
{
	if (**ws == '*')
	{
		(*ws)++;
		iterate_wilds(ws);
	}
}

/**
 * postfix_match - Checks if a string s matches the postfix of
 *                 another string potentially containing wildcards.
 * @s: The string.
 * @p: The postfix.
 *
 * Return: If s and p are identical - a pointer to the null byte
 *                                            located at the end of postfix.
 *         Otherwise - a pointer to the first unmatched character in postfix.
 */
char *postfix_match(char *s, char *p)
{
	int s_len = strlen_no_wilds(s) - 1;
	int p_len = strlen_no_wilds(p) - 1;

	if (*p == '*')
		iterate_wilds(&p);

	if (*(s + s_len - p_len) == *p && *p != '\0')
	{
		p++;
		return (postfix_match(s, p));
	}

	return (p);
}

/**
 * wildcmp - Compares two strings, considering wildcard characters.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared and may contain wildcards.
 *
 * Return: If the strings can be considered identical - 1.
 *         Otherwise - 0.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		iterate_wilds(&s2);
		s2 = postfix_match(s1, s2);
	}

	if (*s2 == '\0')
		return (1);

	if (*s1 != *s2)
		return (0);

	return (wildcmp(++s1, ++s2));
}
