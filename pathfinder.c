#include "header.h"
/**
 * pathfinder - splits all the elements of the path
 * Return: array of strings that are the diff elements of the PATH
 */
char **pathfinder(void)
{
	char *pathtok;
	char *path = _getenv("PATH");
	int x;
	char **splitpath = malloc(sizeof(char) * 1024);

	pathtok = strtok(path, ":");
	for (x = 0; pathtok != NULL; x++)
	{
		splitpath[x] = pathtok;
		pathtok = strtok(NULL, ":");
	}
	splitpath[x] = '\0';
	/*if (path != NULL)
	  free(path);*/
	return (splitpath);
}
