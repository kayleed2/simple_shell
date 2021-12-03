#include "header.h"
/**
 * _strcat- concatenates two strings into one array
 * @src: source array pointer
 * @dest: destination array pointer
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int x = 0;

	if ((dest == NULL) && (src == NULL))
		return (NULL);
	while (*dest != '\0')
	{
		dest++;
		x++;
	}
	while (*src != '\0')
	{
		*dest++ = *src++;
		x++;
	}
	*dest = '\0';
	x++;
	dest = dest - x;
	return (dest);
}
