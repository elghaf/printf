#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

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
