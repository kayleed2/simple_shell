#include "header.h"
/**
 * buildthepath - builds the path to execute
 * @fullpath - destination
 * @material1 - building material
 * @material2 - more material
 */
char *buildthepath(char *fullpath, char *material1, char *material2)
{
	_strcpy(fullpath, material1);
	_strcat(fullpath, "/");
	_strcat(fullpath, material2);
	return (fullpath);
}
