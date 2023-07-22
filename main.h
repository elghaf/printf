#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
void print_char(va_list args, int *count);
void print_string(va_list args, int *count);
void print_percent(int *count);
void print_int(va_list args, int *count);

#endif
