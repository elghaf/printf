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
int helper(int *count, const char *format, va_list args);
int print_int(int num, char sign, char space);

#endif
