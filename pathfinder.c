#include "header.h"
/**
 * pathfinder - splits all the elements of the path
 * Return - array of strings
 */
char **pathfinder(void)
{
	char *pathtok;
	char *path = getenv("PATH");
	int x, len = _strlen(path);
	char **splitpath = malloc(sizeof(char) * 1024);

	pathtok = strtok(path, ":");
	for (x = 0; pathtok != NULL; x++)
	{
		splitpath[x] = pathtok;
		pathtok = strtok(NULL, ":");
	}
	return(splitpath);
}
