#include "header.h"
/**
 * _chardup - copies a character
 * @chr: the character to be copied
 * Return: pointer to array, NULL if chr is NULL
 */
char *_chardup(char chr)
{
	char *p = 0;
	int i;

	if (!chr)
	{
		return (NULL);
	}
	p = malloc(sizeof(char));
	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < 1; i++)
	{
		p[i] = chr;
	}
	return (p);
}
