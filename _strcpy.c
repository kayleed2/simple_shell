# include "header.h"
/**
* _strcpy - prints number of values
* @dest: Pointer to buffer
* @src: Pointer to string
* Description: The above
* Return: Return value is pointer to dest
*/

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i++] = '\0';
	return (dest);
}
