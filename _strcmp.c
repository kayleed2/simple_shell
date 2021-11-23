# include "header.h"
/**
* _strcmp - copies a string
* @s1: String to be compared
* @s2: String to be compared
* Description: The above
* Return: Return value is numerical difference
*/

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (*s1 - *s2 == 0)
		{
			s1++;
			s2++;
		}
	}
	return (*s1 - *s2);
}
