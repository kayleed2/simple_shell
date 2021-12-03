#include "header.h"
/**
 * _getenv - gets environmental variables
 * @var: name
 * Return: path on success
 */
char *_getenv(char *var)
{
	int i;
	size_t l = _strlen(var);

	if (!__environ || !*var || strchr(var, '='))
	return (NULL);

	for (i = 0; __environ[i] && (strncmp(var, __environ[i], l)
								 || __environ[i][l] != '='); i++);
	if (__environ[i])
		return (__environ[i] + l + 1);
	return (NULL);
}
