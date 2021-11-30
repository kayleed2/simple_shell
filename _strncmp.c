# include "header.h"
/**
 * _strncmp - compares a string up to n bytes
 * @s1: String to be compared
 * @s2: String to be compared
 * @n: number of characters to compare
 * Description: The above
 * Return: Return value is numerical difference
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; i <= n; i++)
	{
		if (*s1 - *s2 == 0)
		{
			s1++;
			s2++;
		}
	}
	return (*s1 - *s2);
}
