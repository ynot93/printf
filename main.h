#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int _print_char(va_list args);
int _print_int(va_list args);
int _print_string(va_list args);
int dispatcher(const char specifier, va_list args);
int handle_binary(va_list args);
int handle_u(va_list args);
int handle_o(va_list args);
int handle_x(va_list args);
int handle_X(va_list args);
int handle_S(va_list args);

#endif
