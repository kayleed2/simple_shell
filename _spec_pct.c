#include "header.h"
/**
 * _spec_pct - prints a % char when the % specifier is used
 * @args: not used for this function
 * Return: 1
 */
int _spec_pct(va_list *args)
{
	(void)(args);

	_putchar('%');
	return (1);
}
