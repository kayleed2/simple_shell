#include "header.h"
/**
 * _spec_r - Reverses a string and prints it
 * @args: input string
 * Return: the number of characters printed
 */
int _spec_r(va_list *args)
{
	int l = 0, i, x;
	char *ptr_str = va_arg(*args, char *);
	char *nope = "(null)";

	if (!ptr_str)
	{
		while (*nope != '\0')
		{
			_putchar(nope[x]);
			x++;
		}
	}
	else
	{
		x = _strlen(ptr_str);
		for (i = 0; i < (x - 1); i++)
		{
			ptr_str++;
		}
		while (l < x)
		{
			_putchar(*ptr_str);
			ptr_str--;
			l++;
		}
	}
	return (x);
}
