#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

/* _putchar - stdout */
int _putchar(char c);

/* Function prototypes of my understanding*/
int print_single_char(va_list args);
int print_string(va_list args);
int print_integer(va_list args);
int print_unsigned_integer(va_list args);
int print_octal_integer(va_list args);
int print_hexadecimal(va_list args);
int print_hexadecimal_uppercase(va_list args);

/* _printf - custom printf */
int _printf(const char *format, ...);

#endif /* MAIN_H */
