#include <stdarg.h>
#include "main.h"

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to be written.
 *
 * Return: On success, 1. On error, -1 is returned and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - Custom implementation of printf.
 * @format: The format string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char ch;

	va_start(args, format);

	while ((ch = *format++) != '\0')
	{
		if (ch != '%')
		{
			_putchar(ch);
			count++;
		}
		else
		{
			ch = *format++;
			switch (ch)
			{
				case 'c':
					count += print_char(args);
					break;
				case 's':
					count += print_string(args);
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				case 'd':
				case 'i':
					count += print_int(args);
					break;
				case 'u':
					count += print_unsigned(args);
					break;
				case 'o':
					count += print_octal(args);
					break;
				case 'x':
					count += print_hex(args);
					break;
				case 'X':
					count += print_hex_upper(args);
					break;
				default:
					break;
			}
		}
	}

	va_end(args);
	return count;
}

