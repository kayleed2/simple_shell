# include "header.h"
/**
* _strlen - Prints restates var value
* @s: String to determine length
* Description: The above
* Return: Return value should be void  indicating success
*/

int _strlen(char *s)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}


	return (i);
}
