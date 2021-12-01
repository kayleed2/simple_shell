#include "header.h"
/**
 * _spec_R - ROT13s the string
 * @args: input string argument
 * Return: x
 */
int _spec_R(va_list *args)
{
	char *s = va_arg(*args, char *);
	char *nope = "(null)";
	int x = 0, l;

	l = _strlen(s);
	if (l == 0)
		{
			s = nope;
		}
	while (x < l)
		{
			if ((*s >= 'A' && *s <= 'M') || (*s >= 'a' && *s <= 'm'))
				{
					_putchar((*s + '\0') + 13);
					s++;
					x++;
				}
			else if ((*s >= 'N' && *s <= 'Z') || (*s >= 'n' && *s <= 'z'))
				{
					_putchar((*s + '\0') - 13);
					s++;
					x++;
				}
			else
				{
					_putchar(*s);
					s++;
					x++;
				}
		}
	return (x);
}
