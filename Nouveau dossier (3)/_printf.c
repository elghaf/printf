#include <stdarg.h>
#include "main.h"

/**
 * print_char - Prints one character.
 * @c: The character to be printed.
 * Return: Number of characters printed (always 1)
 */

int print_char(char c)
{
	char character;

	character = c;
	_putchar(character);
	return (1);
}

/**
 * _printf - Prints a formatted string to the standard output.
 * @format: A pointer to a character string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list argument;
	int total_counts = 0, digit, sign, len = 0, num, i;
	char buffer[20];
	char c;
	char *s;

	if (format == NULL)
		return (-1);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	va_start(argument, format);



while (*format != '\0') {
    if (*format == '%') {
        format++;
        switch (*format) {
            case '%':
                print_char('%');
                total_counts++;
                break;
            case 'c':
                c = va_arg(argument, int);
                print_char(c);
                total_counts++;
                break;
            case 's': {
                s = va_arg(argument, char *);
                while (*s != '\0') {
                    print_char(*s);
                    total_counts++;
                    s++;
                }
                break;
            }
            case 'd':
            case 'i': {
                num = va_arg(argument, int);
                sign = 1;
                if (num < 0) {
                    sign = -1;
                    num = -num;
                }
                len = 0;
                do {
                    digit = num % 10;
                    buffer[len] = digit + '0';
                    len++;
                    num /= 10;
                } while (num > 0);

                if (sign == -1) {
                    print_char('-');
                    total_counts++;
                }

                for ( i = len - 1; i >= 0; i--) {
                    print_char(buffer[i]);
                    total_counts++;
                }
                break;
            }
            default:
                break;
        }
        format++;
    } else {
        print_char(*format);
        total_counts++;
        format++;
    }
}

	va_end(argument);

	return (total_counts);
}
