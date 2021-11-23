# include "header.h"
/**
* _strcat - prints number of values
* @dest: Pointer to buffer
* @src: Pointer to string
* Description: The above
* Return: Return value is pointer to dest
*/

char *_strcat(char *dest, char *src)
{
	char *con;
	int dlen;
	int slen;
	int n;
	int i;

	con = dest;
	for (i = 0; src[i] != '\0'; i++)
	{
		slen = i;
	}
	for (i = 0; dest[i] != '\0'; i++)
	{
		dlen = i;
	}
	n = slen + dlen;
	for (i = 0; i <= dlen; i++)
	{
		dest++;
	}
	while (i >= dlen && i <= n + 1)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
		if (i > n + 1)
		{
			dest[i] = '\0';
		}
	}
	return (con);
}
