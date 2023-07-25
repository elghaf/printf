#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_char - This function prints character
 * @c: The character itself
 *
 * Return: returns the character passed
 */

int print_char(int c)
{
	return (write(1, &c, 1));
}
/**
 * print_string - This fuction prints a string
 * @str: This is the pointer to the string
 *
 * Return: returns the formatted string
 */

int print_string(const char *str)
{
	int len = 0;

	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (str[len])
		len++;
	return (write(1, str, len));
}
/**
 * helper - The function prints char and strings
 * @count: count number
 * @format: This is the pointer to the string
 * @args: Represents the list of arguments
 *
 * Return: return -1 otherwise no return
 */

int helper(int *count, const char *format, va_list args)
{
	char *str;
	char characters, percent = '%';

	if (*format == '\0')
	{
		return (-1);
	}
	else if (*format == 'c')
	{
		characters = va_arg(args, int);
		*count += print_char(characters);
	}
	else if (*format == 's')
	{
		str = va_arg(args, char*);
		*count += print_string(str);
	}
	else if (*format == '%')
	{
		*count += write(1, &percent, 1);
	}
	else if (*format == 'd' || *format == 'i')
	{
		int integer_nb = va_arg(args, int);
		char neg_pos = 0;
		char space = 0;

		format--;
		while (*++format == '+' || *format == ' ')
		{
			neg_pos = !(*format == '+') ? 0 : 1;
		}
		*count += print_int(integer_nb, neg_pos, space);
	}
	else
	{
		*count += write(1, "%", 1);
		*count += write(1, format, 1);
	}
	return (0);
}

/**
 * _printf - This fuction prints the printf functionality
 * @format: Represents the pointer to the string format.
 *@...: any other arguments.
 *
 * Return: return the number of string.
 */
int _printf(const char *format, ...)
{
	va_list arguments;
	int index_counter = 0;

	if (format == NULL)
	{
		return (-1);
	}
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	va_start(arguments, format);
	for (; *format; format++)
	{
		if (*format == '%')
		{
			format++;
			helper(&index_counter, format, arguments);
		}
		else
		{
			index_counter += write(1, format, 1);
		}
	}
	va_end(arguments);
	return (index_counter);
}
