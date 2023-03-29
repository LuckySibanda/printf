#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct print_fn - Struct containing a print function
 * and its associated format specifier
 * @specifier: The format specifier
 * @fn: The print function
 */
typedef struct print_fn
{
	char *specifier;
	int (*fn)(va_list);
} print_fn_t;

/**
 * struct print_specifiers - Struct containing a format specifier
 * and its associated print function
 * @specifier: The format specifier
 * @print_fn: The print function associated with the format specifier
 */
typedef struct print_specifiers
{
	char specifier;
	int (*print_fn)(va_list);
} print_specifiers_t;

int _printf(const char *format, ...);

#endif /* MAIN_H */
