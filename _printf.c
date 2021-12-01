#include "header.h"
/**
 * _printf - prints a formatted string to output
 * @format: input string to format and print
 * Return: total, the total number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int (*func)(va_list *); /* funct ptr to find funct for spec */
	int x = 0;  /* input incrementer variable */
	int tot = 0;  /* length of output string */

	va_start(args, format);
	if (!format)
		{
			return (-1);
		}
	while (format && format[x])
		{
			if (format[x] == '%')
				{
					x++;
					func = _get_function(format[x]);
					if (func != NULL)
						{
							tot += func(&args);
						}
					else
						{
							tot +=_putchar('%');
							tot += _putchar(format[x]);
						}
					x++;
				}
			else
				{
					tot += _putchar(format[x]);
					x++;
				}
		}
	va_end(args);
	return (tot);
}
