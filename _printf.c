#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Prints a formatted string to the standard output.
 * @format: A pointer to a character string.
 *
 * Return: The number of characters printed (excluding the null byte used to
 * end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list my_args;
	int count = 0;
	char buffer[20];
	char *s;
	int num, len, i;

	if (format == NULL)
		return -1;

	va_start(my_args, format);
	while (*format)
	{
		if (*format != '%')
		{
			m_putchars(*format);
			count++;
		}
		else
		{
			format++;
			switch (*format)
			{
			case 'c':
				m_putchars(va_arg(my_args, int));
				count++;
				break;
			case 's':
				s = va_arg(my_args, char *);
				len = 0;
				while (s[len])
					len++;
				count += len;
				fputs(s, stdout);
				break;
			case 'd':
			case 'i':
				num = va_arg(my_args, int);
				if (num < 0)
				{
					m_putchars('-');
					count++;
					num = -num;
				}
				len = 0;
				do {
					buffer[len++] = num % 10 + '0';
					num /= 10;
				} while (num > 0);
				for (i = len - 1; i >= 0; i--)
				{
					m_putchars(buffer[i]);
				}
				count += len;
				break;
			default:
				m_putchars('%');
				m_putchars(*format);
				count += 2;
				break;
			}
		}
		format++;
	}
	va_end(my_args);
	return count;
}
