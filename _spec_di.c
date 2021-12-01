#include "header.h"
/**
 * print_min - prints int_min
 * Return: i
 */
int print_min(void)
{
	int i;
	char *int_min = "-2147483648";

	i = 0;
	while (*int_min != '\0')
		{
			_putchar(*int_min);
			i++;
			int_min++;
		}
	return (i);
}

/**
 * _spec_di - prints integer and returns how many character printed
 * @args: number to print
 * Return: number of characters printed.
 */
int _spec_di(va_list *args)
{
	int i;
	char s[13];
	char *stra;
	int stri = va_arg(*args, int);

	if (stri == INT_MIN)
		{
			i = print_min();
			return (i);
		}
	stra = _itoa(stri, s, 10);

	i = 0;
	while (stra[i] != '\0')
		{
			_putchar(stra[i]);
			i++;
		}
	return (i);
}
