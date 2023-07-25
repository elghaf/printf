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
	char ch, percent = '%';

	if (*format == '\0')
	{
		return (-1);
	}
	else if (*format == 'c')
	{
		ch = va_arg(args, int);
		*count += print_char(ch);
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
		int num = va_arg(args, int);
		char sign = 0;
		char space = 0;

		format--;
		while (*++format == '+' || *format == ' ')
			sign = (*format == '+') ? 1 : 0;

		*count += print_int(num, sign, space);
	}
	else
	{
		*count += write(1, "%", 1);
		*count += write(1, format, 1);
	}
	return (0);
}

/**
 * print_int - The function handles d and i specifiers
 *@num: The integer to be printed
 *@sign: The sign of the integer
 *@space: The space between the integer
 *
 *Return: Return count.
 */

int print_int(int num, char sign, char space)
{
	int count = 0;
	char buffer[12];
	int len = 0;

	if (num == INT_MIN)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}

	if (num < 0)
	{
		count += write(1, "-", 1);
		num = -num;
	} else if (sign)
	{
		count += write(1, "+", 1);
	} else if (space)
	{
		count += write(1, " ", 1);
	}
	else if (num == 0)
	{
		count += write(1, "0", 1);
		return (count);
	}

	do {
		buffer[len++] = '0' + num % 10;
		num /= 10;
	} while (num > 0);

	while (len > 0)
		count += write(1, &buffer[--len], 1);

	return (count);
}


/**
 * _printf - This fuction prints the printf functionality
 * @format: Represents the pointer to the string
 *@...: any other arguments
 *
 * Return: return the number of words outputed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
	{
		return (-1);
	}
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	va_start(args, format);
	for (; *format; format++)
	{
		if (*format == '%')
		{
			format++;
			helper(&count, format, args);
		}
		else
		{
			count += write(1, format, 1);
		}
	}
	va_end(args);
	return (count);
}
