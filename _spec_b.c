#include "header.h"
/**
 * _spec_b - prints integer and returns how many character printed
 * @args: number to print
 * Return: the number of numbers printed
 *
 */
int _spec_b(va_list *args)
{
	int i;
	char s[30];
	int stri = va_arg(*args, int);
	char *stra = _itoa(stri, s, 2);

	i = 0;
	while (stra[i] != '\0')
		{
			_putchar(stra[i]);
			i++;
		}
	return (i);
}
