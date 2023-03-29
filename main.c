#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct print_fn - Struct to store format and corresponding print function
 * @format: The format specifier
 * @fn: The corresponding print function
 */
typedef struct print_fn
{
	char format;
	int (*fn)(va_list);
} print_fn_t;

/* Function prototypes */
int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

#endif /* MAIN_H */
