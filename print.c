#include "main.h"

/**
 * print_char - Prints a character
 *
 * @valist: A list of arguments containing
 *          the character to be printed
 *
 * Return: The number of characters printed
 */
int print_char(va_list valist)
{
	char c = va_arg(valist, int);

	_putchar(c);

	return (1);
}

/**
 * print_string - Prints a string of characters
 *
 * @valist: A list of arguments containing
 *          the string to be printed
 *
 * Return: The number of characters printed
 */
int print_string(va_list valist)
{
	char *str = va_arg(valist, char *);
	int len = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		_putchar(*str);
		str++;
		len++;
	}

	return (len);
}

/**
 * print_percent - Prints a percent symbol
 *
 * @valist: A list of arguments (unused)
 *
 * Return: The number of characters printed
 */
int print_percent(va_list valist __attribute__((unused)))
{
	_putchar('%');

	return (1);
}

/**
 * print_int - Prints an integer
 *
 * @valist: A list of arguments containing
 *          the integer to be printed
 *
 * Return: The number of characters printed
 */
int print_int(va_list valist)
{
	int num = va_arg(valist, int);
	int num_len = 0;
	int divisor = 1;

	if (num < 0)
	{
		_putchar('-');
		num_len++;

		if (num == INT_MIN)
		{
			/*
			 * Convert INT_MIN + 1 to positive,
			 * and print the first digit ('2')
			 */
			num++;
			num_len++;
			_putchar('2');
			num %= divisor * 10;
			divisor /= 10;
		}

		num = -num;
	}

	/* Determine the divisor */
	while (num / divisor >= 10)
		divisor *= 10;

	/* Print each digit */
	while (divisor != 0)
	{
		_putchar(num / divisor + '0');
		num %= divisor;
		divisor /= 10;
		num_len++;
	}

	return (num_len);
}
