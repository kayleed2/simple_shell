#include "header.h"
/**
 * _strdup - This function creates an array
 * @str: string to be copied
 * Return: pointer to array, Null if str is null
 */

char *_strdup(char *str)
{
	char *p;
	int i;
	int size;

	if (str == NULL)
	{
		return (NULL);
	}
	size = _strlen(str);
	p = malloc((size + 1) * sizeof(char));
	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		p[i] = str[i];
	}
	return (p);
}
