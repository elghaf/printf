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
	va_list arguments;
	int character_count = 0;
	char current_char;

	va_start(arguments, format);

	while ((current_char = *format++) != '\0')
	{
		if (current_char != '%')
		{
			_putchar(current_char);
			character_count++;
		}
		else
		{
			current_char = *format++;
			switch (current_char)
			{
				case '%':
				_putchar('%');
				character_count++;
				break;
				case 'c':
					character_count += print_single_char(arguments);
					break;
				case 's':
					character_count += print_string(arguments);
					break;
				case 'd':
				case 'i':
					character_count += print_integer(arguments);
					break;
				case 'u':
					character_count += print_unsigned_integer(arguments);
					break;
				case 'o':
					character_count += print_octal_integer(arguments);
					break;
				case 'x':
					character_count += print_hexadecimal(arguments);
					break;
				case 'X':
					character_count += print_hexadecimal_uppercase(arguments);
					break;
				default:
					break;
			}
		}
	}

	va_end(arguments);
	return (character_count);
}
