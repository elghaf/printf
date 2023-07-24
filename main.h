#ifndef MYHEADER_H
#define MYHEADER_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

int _printf(const char *format, ...);

/* Funtions to print chars and strings */
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);

/* Functions to print numbers */
int print_int(va_list);
int print_binary(va_list);

#endif
