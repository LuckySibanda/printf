#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - Prints a character to standard output.
 * @args: A va_list pointing to the argument to print.
 * @count: A pointer to an integer representing the count of characters printed.
 */
void print_char(va_list args, int *count)
{
	char c = va_arg(args, int);
	write(1, &c, 1);
	(*count)++;
}

/**
 * print_string - Prints a string to standard output.
 * @args: A va_list pointing to the argument to print.
 * @count: A pointer to an integer representing the count of characters printed.
 */
void print_string(va_list args, int *count)
{
	char *str = va_arg(args, char *);
	while (*str)
	{
		write(1, str, 1);
		(*count)++;
		str++;
	}
}

/**
 * print_percent - Prints a percent sign to standard output.
 * @count: A pointer to an integer representing the count of characters printed.
 */
void print_percent(int *count)
{
	write(1, "%", 1);
	(*count)++;
}

/**
 * print_int - Prints an integer to standard output.
 * @args: A va_list pointing to the argument to print.
 * @count: A pointer to an integer representing the count of characters printed.
 */
void print_int(va_list args, int *count)
{
	int n = va_arg(args, int);
	int len = 1;

	if (n < 0)
	{
		write(1, "-", 1);
		(*count)++;
		n = -n;
	}

	while (n / len >= 10)
		len *= 10;

	while (len > 0)
	{
		write(1, &("0123456789"[(n / len) % 10]), 1);
		(*count)++;
		len /= 10;
	}
}

/**
 * _printf - Prints a formatted string to standard output.
 * @format: A pointer to a string of characters to be printed.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					print_char(args, &count);
					break;
				case 's':
					print_string(args, &count);
					break;
				case '%':
					print_percent(&count);
					break;
				case 'd':
					print_int(args, &count);
					break;
				case 'i':
					print_int(args, &count);
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
