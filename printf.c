#include <stdarg.h>
#include "main.h"

/**
 * _printf - Prints a formatted string to the standard output.
 * @format: A pointer to a character string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0, digit, sign, len, num, i;
	char buffer[20];
	char c;
	char *s;

	if (format == NULL)
		return (-1);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	va_start(ap, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else if (*format == 'c')
			{
				c = (char) va_arg(ap, int);
				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				s = va_arg(ap, char *);
				while (*s != '\0')
				{
					_putchar(*s);
					count++;
					s++;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				num = va_arg(ap, int);
				sign = 1;
				if (num < 0)
				{
					sign = -1;
					num = -num;
				}
				len = 0;
				do {
					digit = num % 10;
					buffer[len] = digit + '0';
					len++;
					num /= 10;
				} while (num > 0);

				if (sign == -1)
				{
					_putchar('-');
					count++;
				}

				for (i = len - 1; i >= 0; i--)
				{
					_putchar(buffer[i]);
					count++;
				}
			}
			format++;
		}
		else
		{
			_putchar(*format);
			count++;
			format++;
		}
	}

	va_end(ap);

	return (count);
}
