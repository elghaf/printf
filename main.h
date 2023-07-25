#ifndef PRINTF
#define PRINTF

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

/**
 * the function that i created for this project.
 */
int _putchar(char c);
int _printf(const char *format, ...);
int need_function_formated(int *count, const char *format, va_list args);
int print_int(int integer_print, char neg_pos, char integer_space);

#endif
