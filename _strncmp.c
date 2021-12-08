# include "header.h"
/**
 * _strncmp - compares a string up to n bytes
 * @s1: String to be compared
 * @s2: String to be compared
 * @n: number of characters to compare
 * Description: The above
 * Return: Return value is numerical difference
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	int val = 0;

	if (*s1 + n > *s2 + n)
		val = 1;
	else if (*s1 + n < *s2 + n)
		val = -1;
	else
		val = 0;
	return (val);
}
