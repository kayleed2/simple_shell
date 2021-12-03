#include "header.h"
/**
 * splitter - Splits string into tokens
 * @str: String to split
 * Return: Pointer to array of strings
 */

char **splitter(char *str)
{
	int len = _strlen(str);
	int i;
	char *string = NULL;
	char **holder = NULL;

	holder = malloc(sizeof(char *) * (len * 2));
	string = strtok(str, " ");
	for (i = 0; string != NULL; i++)
	{
		holder[i] = string;
		string = strtok(NULL, " ");
	}
	holder[i] = '\0';
	return (holder);
}
