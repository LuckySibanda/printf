#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the
 * null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0, printed_chars = 0;
	char *buffer;

	if (format == NULL)
		return (-1);

	buffer = malloc(1024 * sizeof(char));
	if (buffer == NULL)
		return (-1);

	va_start(args, format);

	while (*(format + len))
	{
		if (*(format + len) == '%')
		{
			len++;
			printed_chars += handle_format_specifiers(buffer,
									*(format + len),
									args);
		}
		else
		{
			*(buffer + printed_chars) = *(format + len);
			printed_chars++;
		}

		len++;
	}

	va_end(args);

	write(1, buffer, printed_chars);
	free(buffer);

	return (printed_chars);
}
