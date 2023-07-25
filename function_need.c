#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_helper - Prints characters and strings based on format specifiers.
 * @count_ptr: A pointer to the count number.
 * @format: A pointer to the format string.
 * @args: Represents the variable argument list.
 *
 * Return: Returns -1 on error, otherwise no return value.
 */

int print_helper(int *count_ptr, const char *format, va_list args)
{
    char *str_arg;
    char ch_arg;
    char percent = '%';

    if (*format == '\0')
    {
        return (-1);
    }

    switch (*format)
    {
        case 'c':
            ch_arg = va_arg(args, int);
            *count_ptr += print_char(ch_arg);
            break;
        case 's':
            str_arg = va_arg(args, char*);
            *count_ptr += print_string(str_arg);
            break;
        case '%':
            *count_ptr += _putchar(1, &percent, 1);
            break;
        case 'd':
        case 'i':
        {
            int num_arg = va_arg(args, int);
            char sign = 0;
            char space = 0;

            format--;
            while (*++format == '+' || *format == ' ')
                sign = (*format == '+') ? 1 : 0;

            *count_ptr += print_int(num_arg, sign, space);
            break;
        }
        default:
            *count_ptr += _putchar(1, "%", 1);
            *count_ptr += _putchar(1, format, 1);
            break;
    }

    return (0);
}
