#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
int handle_format_specifiers(char *buffer, char format_specifier, va_list
		args);
int print_c(char *buffer, va_list args);
int print_s(char *buffer, va_list args);
int print_percent(char *buffer);

#endif /* MAIN_H */

