#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"

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
