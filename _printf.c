#include <stdarg.h>
#include "main.h"
#include <string.h>

/**
 * print_char - print character
 * @character: character
 * Return: int
 */

int print_char(char character)
{
	m_putchar(character);
	return (1);
}

/**
 * print_string - print string.
 * @char_string: character string.
 * Return: 0
 */

int print_string(const char *char_string)
{
	int i = 0, len_string;

	if (char_string == NULL)
	{
		char_string = "(null)";
		len_string = strlen(char_string);
		while (i < len_string)
		{
			/* code */
			my_putchar(char_string[i]);
			i++;
		}
		return (len_string);
	}
	else
	{
		len_string = strlen(char_string);
		while (i < len_string)
		{
			/* code */
			my_putchar(char_string[i]);
			i++;
		}	
		return (len_string);
	}
}

/**
 * process_format - entry point
 * @format: char
 * @args: va_list
 * Return: int
 */

int process_format(const char *format, va_list args) {
    int ind_count = 0;
    char c;

    typedef int (*PrintFunction)(va_list);
    PrintFunction print_functions[256] = { NULL };

    print_functions['c'] = print_char;
    print_functions['s'] = print_string;
    print_functions['%'] = print_percent;

    while ((c = *format++)) {
        if (c == '%') {
            char next_char = *format++;
            PrintFunction print_func = print_functions[(unsigned char)next_char];
            if (print_func) {
                ind_count += print_func(args);
            } else {
                putchar('%');
                putchar(next_char);
                ind_count += 2;
            }
        } else {
            putchar(c);
            ind_count++;
        }
    }
    return (ind_count);
}

/**
 * _printf - printf.
 * @format: character.
 * Return: 0
 */

int _printf(const char *format, ...)
{
	va_list args;
	int ind_count;

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	if (strcmp(format, "% ") == 0 || strcmp(format, "%") == 0)
		return (-1);

	ind_count = process_format(format, args);

	va_end(args);
	return (ind_count);
}
