#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * _printf - custom printf function
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg_list;
	int i, j, printed = 0;
	char *str;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					_putchar(va_arg(arg_list, int));
					printed++;
					break;
				case 's':
					str = va_arg(arg_list, char *);
					if (str == NULL)
					{
						str = "(null)";
					}
					for (j = 0; str[j] != '\0'; j++)
					{
						_putchar(str[j]);
						printed++;
					}
					break;
				case '%':
					_putchar('%');
					printed++;
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					printed += 2;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			printed++;
		}
	}

	va_end(arg_list);

	return (printed);
}
