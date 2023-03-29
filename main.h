#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdarg.h>

/**

struct print_fn - Struct print function
@fmt: The format
@fn: The function
*/
typedef struct print_fn
{
char *fmt;
int (*fn)(va_list);
} print_fn_t;
int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_percent(va_list args);

#endif /* MAIN_H */
