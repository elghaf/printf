#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

/* Function prototypes for handling each conversion specifier */
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_hex_upper(va_list args);

/* _putchar - Writes a character to stdout. */
int _putchar(char c);

/* _printf - Custom implementation of printf. */
int _printf(const char *format, ...);

#endif /* MAIN_H */
