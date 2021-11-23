#include "header.h"
/**
 * splitter - Splits string into tokens
 * @str: String to split
 * Return: Pointer to array of strings
 */

char **splitter(char *str)
{
	long unsigned int len = strlen(str);
	int i;
	char *string;
	char **holder;

	holder = malloc(sizeof(char) * (len + 3));
    string = strtok(str, " ");
	for (i = 0; string != NULL; i++)
    {
		holder[i] = string;
		string = strtok(NULL, " ");
	}
    return (holder);
}
