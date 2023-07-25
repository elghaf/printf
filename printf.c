#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Prints formatted output to stdout.
 * @format: A pointer to the format string.
 * @...: Any arguments required by the format.
 * Return: On success, 
 * 	       the number of characters printed is returned.
 *         On error, a negative value is returned.
 **/

int _printf(const char *format, ...)
{
	int index_counteur = 0;
	va_list arguments;

	if (format == NULL)
	{
		return (-1);
	}
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(arguments, format);
	while (*format)
	{
	    if (*format == '%')
	    {
	        format++;
	        prin_helper(&index_counteur, format, arguments);
	    }
	    else
	    {
	        index_counteur += _putchar(1, format, 1);
	    }
	    format++;
	}
	va_end(arguments);
	return (index_counteur);
}