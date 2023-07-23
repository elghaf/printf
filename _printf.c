#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

/**
 * _printf - Custom implementation of printf with limited conversion specifiers.
 * @format: The format string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte used to end
 *         output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int index = 0;
	int inner_index;
	int chars_printed = 0;
	char ch;

	va_start(args, format);

	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;

			if (format[index] == '%')
			{
				_putchar('%');
				chars_printed++;
			}
			else if (format[index] == 'c')
			{
				ch = va_arg(args, int);
				_putchar(ch);
				chars_printed++;
			}
			else if (format[index] == 's')
			{
				char *str = va_arg(args, char *);

				inner_index = 0;
				while (str[inner_index] != '\0')
				{
					_putchar(str[inner_index]);
					chars_printed++;
					inner_index++;
				}
			}
			else
			{
				_putchar('%');
				_putchar(format[index]);
				chars_printed += 2;
			}
		}
		else
		{
			_putchar(format[index]);
			chars_printed++;
		}
		index++;
	}

	va_end(args);
	return chars_printed;
}
