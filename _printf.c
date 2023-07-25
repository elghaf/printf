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
 * print_integer - Print an integer
 * @args: A va_list containing the integer to be printed
 *
 * Return: The number of characters printed
 */
int print_integer(int num)
{
	char buffer[20]; /*Assume that 20 charaters are enough for an int*/
	int count = 0;
	int i = sizeof(buffer) - 1;

	if (num == 0)/*Handle Zero */
	{
		buffer[0] = 48;
		buffer[1] = 0;
		count++;
		write(1, buffer, 1);
		return (count);
	}
	if (num < 0)/*Handle Negative numbers */
	{
		write(1, "-", 1);
		count++;
		num = -num;
	}
	buffer[i--] = 0;/*Converts the integer to a string(reversed)*/
	do {
		buffer[i--] = 48 + (num % 10);
		num /= 10;
		count++;
	} while (num > 0);
	write(1, buffer + i + 1, count);/*Write the string to the stdout */
	return (count);
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
				case 'd':
				case 'i':
					total_count += print_integer(va_arg(args, int));
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
