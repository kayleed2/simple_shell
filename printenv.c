#include "header.h"
/**
 * printenv - Prints env
 * Return: 0 on success, -1 on failure
 */

void printenv(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		_printf("%s\n", environ[i]);
}
