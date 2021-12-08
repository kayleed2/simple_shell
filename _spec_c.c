#include "header.h"
/**
 * _spec_c - returns a string with a character in it
 * @args: input character variable
 * Return: 1
 */
int _spec_c(va_list *args)
{
	_putchar(va_arg(*args, int));

	return (1);
}
