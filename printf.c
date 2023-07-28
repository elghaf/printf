#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_char_of_string - This fuction prints char of str.
 * @str_char: This is the pointer to the char str.
 *
 * Return: returns the formatted string
 */

int print_char_of_string(const char *str_char)
{
	int lengh_count = 0;

	if (str_char == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (str_char[lengh_count])
		lengh_count++;
	return (write(1, str_char, lengh_count));
}
/**
 * helper - The function prints strings.
 * @index_c: count number
 * @format: This is the pointer to the string.
 * @args: any arguments.
 *
 * Return: return -1 otherwise no return
 */

int helper(int *index_c, const char *format, va_list args)
{
	char *str;
	char characters, ch = '%';

	if (*format == '\0')
	{
		return (-1);
	}
	else if (*format == 'c')
	{
		characters = va_arg(args, int);
		*index_c += print_character(characters);
	}
	else if (*format == 's')
	{
		str = va_arg(args, char*);
		*index_c += print_char_of_string(str);
	}
	else if (*format == '%')
	{
		*index_c += write(1, &ch, 1);
	}
	else if (*format == 'd' || *format == 'i')
	{
	int integer_nb = va_arg(args, int);
	int j = 0;
	int indexo = 0;
	char neg_pos = 0;
	char integer_space = 0;

		format--;
		while (*++format == '+' || *format == ' ')
		{
			j++;
			neg_pos = !(*format == '+') ? 0 : 1;
		}
		*index_c += print_int(integer_nb, neg_pos, integer_space);
		indexo++;
	}
	else
	{
		*index_c += write(1, "%", 1);
		*index_c += write(1, format, 1);
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
	int index_counter = 0, i = 0;

	if (format == NULL)
	{
		return (-1);
	}
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	va_start(arguments, format);
	for (i = 0; *format; format++)
	{
		if (*format == '%')
		{
			/*helper function to define the format of char*/
			i++;
			format++;
			helper(&index_counter, format, arguments);
		}
		else
		{
			i++;
			index_counter = index_counter + write(1, format, 1);
		}
	}
	va_end(arguments);
	return (index_counter);
}
