#include "main.h"

/**
 * print_char - Prints a char to stdout
 * @args: List of arguments
 *
 * Return: Number of chars printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);

	return (1);
}

/**
 * print_string - Prints a string to stdout
 * @args: List of arguments
 *
 * Return: Number of chars printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);

	return (i);
}

/**
 * print_percent - Prints a percent sign to stdout
 * @args: List of arguments
 *
 * Return: Number of chars printed
 */
int print_percent(__attribute__((unused))va_list args)
{
	_putchar('%');
	return (1);
}
