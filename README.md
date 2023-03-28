Custom printf function

This project implements a custom version of the printf function in C, which is a standard function used to output formatted data. The custom printf function supports the following format specifiers:

%c: prints a single character
%s: prints a string
%%: prints a percent sign
%d, %i: prints a signed integer
%u: prints an unsigned integer
%o: prints an unsigned integer in octal notation
%x, %X: prints an unsigned integer in hexadecimal

Usage

To use the custom printf function, include the header file "main.h" in your C file, and call the printf function with the desired format string and any necessary arguments.

Compilation

To compile the printf function and the example program, run the following command in the terminal

gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
