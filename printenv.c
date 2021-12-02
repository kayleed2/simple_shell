#include "header.h"
/**
 * printenv - Prints env
 * Return: 0 on success, -1 on failure
 */

int printenv(void)
{
	int i = 0;

	while (environ[i] != NULL)
		_printf("%s\n", environ[i++]);
	return (0);

}
