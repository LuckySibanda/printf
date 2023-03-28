#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Prints a formatted string to standard output.
 *
 * @format: A pointer to a string of characters to be printed.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char *str;
	char c;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
				c = va_arg(args, int);
				write(1, &c, 1);
				count++;
				break;

			case 's':
				str = va_arg(args, char *);
				while (*str)
				{
					write(1, str, 1);
					count++;
					str++;
				}
				break;

			case '%':
				write(1, "%", 1);
				count++;
				break;

			default:
				write(1, &format[i - 1], 2);
				count += 2;
				break;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}

	va_end(args);

	return (count);
}

