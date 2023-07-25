#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"


/**
 * character_to_print - This function to prints character.
 * @character: The character.
 *
 * Return: returns the character to write.
 */

int character_to_print(int character)
{
	return (write(1, &character, 1));
}

/**
 * string_to_print - This fuction to prints a str(string)
 * @string_pointer: the args pointer to the str(string)
 *
 * Return: returns the string.
 */
int string_to_print(const char *string_pointer)
{
	int lengh_of_string = 0;

	if (lengh_of_string == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (string_pointer[lengh_of_string])
		lengh_of_string++;
	return (write(1, string_pointer, lengh_of_string));
}

/**
 * need_function - The function prints char and strings
 * @index_counter: count number
 * @format: This is the pointer to the string
 * @args: Represents the list of arguments
 *
 * Return: return -1 otherwise no return
 */

int need_function(int *index_counter, const char *format, va_list args)
{
	char *str;
	char characters;
    char percentage = '%';

	if (*format == '\0')
	{
		return (-1);
	}
	else if (*format == 'c')
	{
		characters = va_arg(args, int);
		*index_counter += character_to_print(characters);
	}
	else if (*format == 's')
	{
		str = va_arg(args, char*);
		*index_counter += string_to_print(str);
	}
	else if (*format == '%')
	{
		*index_counter += write(1, &percentage, 1);
	}
	else if (*format == 'd' || *format == 'i')
	{
		int num = va_arg(args, int);
		char sign = 0;
		char space = 0;

		format--;
		while (*++format == '+' || *format == ' ')
			sign = (*format == '+') ? 1 : 0;

		*index_counter += print_int(num, sign, space);
	}
	else
	{
		*index_counter += write(1, "%", 1);
		*index_counter += write(1, format, 1);
	}
	return (0);
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
			need_function(&count, format, args);
		}
		else
		{
			count += write(1, format, 1);
		}
	}
	va_end(args);
	return (count);
}
