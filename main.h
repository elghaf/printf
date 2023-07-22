#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAM {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONV_LOWERCASE       1
#define CONV_UNSIGNED        2

/**
 * struct param - param struct
 *
 * @unsign:  for unsigned value
 * @plus_f: for + flag characters
 * @space_f: for space flag characters
 * @hash_f: for # flag characters
 * @zero_f: for zero flag characters
 * @minus_f: for - flag characters
 *
 * @l_m: for l length modifiers
 * @h_m: for h length modifiers
 *
 * @width_f:  field width for non-custom conversion specifiers.
 * @precision_f: precision for non-custom conversion specifiers.
 */
typedef struct param
{
	unsigned int unsign             : 1;
	unsigned int plus_f             : 1;
	unsigned int space_f            : 1;
	unsigned int hash_f             : 1;
	unsigned int zero_f             : 1;
	unsigned int minus_f            : 1;

	unsigned int width_f;
	unsigned int precision_f;

	unsigned int l_m                : 1;
	unsigned int h_m                : 1;
} paramter;
/**
 * struct specifi - Struct specifier
 * @specifier: format
 * @f: function
 */
typedef struct specifi
{
	char *specifier;
	int (*f)(va_list, paramter *);
} spec;

int _puts(char *str);
int _putchar(int c);
int _strlen(char *s);

int prints_c(va_list p, paramter *param);
int prints_s(va_list p, paramter *param);
int prints_per(va_list p, paramter *param);

void get_params(paramster *param, va_list p);
char *catsh_pre(char *p, paramter *param, va_list p);
int get_f(char *s, paramter *param);
char *catsh_wid(char *s, paramter *param, va_list p);
int catsh_mod(char *s, paramter *param);
int (*catsh_spec(char *s))(va_list p, paramter *param);
int catsh_printfunction(char *s, va_list p, paramter *param);

int _printf(const char *format, ...);
#endif
