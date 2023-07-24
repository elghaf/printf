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
	char character;

	character = c;
	m_putchars(character);
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
		m_putchars(str[index]);
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
	int total_count = 0, i;
	char character;
	char buffer[20];
				va_list ap;
				int digit, count = 0, digit, sign, len, num, i;
				char buffer[20];
				char c;
				char *s;                

	while ((character = *format))
	{
		if (character == '%')
		{
			format++;

			switch (*format)
			{
			case 'd':
            case 'i': {
				num = va_arg(args, int);
				sign = 1;
                if (num < 0) {
                    sign = -1;
                    num = -num;
                }
				do {
                    digit = num % 10;
                    buffer[len] = digit + '0';
                    len++;
                    num /= 10;
                } while (num > 0);

                if (sign == -1) {
                    m_putchars('-');
                    count++;
                }

                for (i = len - 1; i >= 0; i--) {
                    m_putchars(buffer[i]);
                    count++;
                }
				total_count = count;
                break;
            }
				case '%':
					m_putchars('%');
					total_count++;
					break;
				case 'c':
					total_count += print_char(va_arg(args, int));
					break;
				case 's':
					total_count += print_string(va_arg(args, const char *));
					break;
				default:
					m_putchars('%');
					m_putchars(*format);
					total_count += 2;
					break;
			}
		}
		else
		{
			m_putchars(c);
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

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		va_end(args);
		return (-1);
	}
	if (format == NULL)
	{
		va_end(args);
		return (-1);
	}
		
	if (!format || (format[0] == '%' && !format[1]))
	{
		va_end(args);
		return (-1);
	}
	if (format[0] == '%' && format[1] == ' ' && !format[2])
	{
		va_end(args);
		return (-1);
	}
	if (strcmp(format, "% ") == 0 || strcmp(format, "%") == 0)
	{
		va_end(args);
		return (-1);
	}
	va_start(args, format);
	total_count = process_format(format, args);

	va_end(args);
	return (total_count);
}
