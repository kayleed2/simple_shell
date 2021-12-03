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

	if (!__environ || !*var || _strchr(var, '='))
	return (NULL);

	for (i = 0; __environ[i] && (_strncmp(var, __environ[i], l)
								 || __environ[i][l] != '='); i++);
	if (__environ[i])
		return (__environ[i] + l + 1);
	return (NULL);
}
/**
 * _strchr - Locates a character in a string.
 *
 * @s: the string to be searched
 * @c: The character to find
 *
 * Return: The pointer to the first occurence of c, or NULL if not found.
 */
char *_strchr(char *s, char c)
{
	unsigned int i;
	char *p = s;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (p);
		}
		p = p + 1;
	}
return (NULL);
}
