#include <stdarg.h>
#include "main.h"
#include <string.h>

/**
 * print_char - Prints a single character
 * @c: The character to be printed
 * Return: Number of characters printed (always 1)
 */

int print_char(char c)
{
	my_putchar(c);
	return (1);
}

/**
 * print_string - Prints a string
 * @str: The string to be printed
 * Return: Number of characters printed
 */

int print_string(const char *str)
{
	int index = 0, len_of_our_string;

	if (str == NULL)
		str = "(null)";

	len_of_our_string = strlen(str);
	while (index < len_of_our_string)
	{
		/* code */
		my_putchar(str[index]);
		index++;
	}

	return (len_of_our_string);
}

/**
 * process_format - Processes the format string and prints accordingly
 * @format: The format string
 * @args: The va_list containing arguments
 * Return: Total number of characters printed
 */

int process_format(const char *format, va_list args)
{
	int total_count = 0;
	char c;

	while ((c = *format))
	{
		if (c == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					total_count += print_char(va_arg(args, int));
					break;
				case 's':
					total_count += print_string(va_arg(args, const char *));
					break;
				case '%':
					my_putchar('%');
					total_count++;
					break;
				default:
					my_putchar('%');
					my_putchar(*format);
					total_count += 2;
					break;
			}
		}
		else
		{
			my_putchar(c);
			total_count++;
		}
		format++;
	}
	return (total_count);
}

/**
 * _printf - Prints formatted output
 * @format: The format string
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int total_count;

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		va_end(args);
		return (-1);
	}

	if (strcmp(format, "% ") == 0 || strcmp(format, "%") == 0)
	{
		va_end(args);
		return (-1);
	}

	total_count = process_format(format, args);

	va_end(args);
	return (total_count);
}
