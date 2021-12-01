#include "header.h"
/**
 * _spec_s - takes input string and copies it to new pointer
 * @args: input string variable
 * Return: number of characters printed
 */
int _spec_s(va_list *args)
{
	char *ptr_str = va_arg(*args, char *);
	int x = 0;

	if (!ptr_str)
		ptr_str = "(null)";
	while (ptr_str[x] != '\0')
		{
			_putchar(ptr_str[x]);
			x++;
		}
	return (x);
}
