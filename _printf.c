#include "main.h"
/**
 * _printf - ac lone to the built in printf
 * @format: format string
 * Return: number of charecters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	const char *t;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	t = format;

	while (*t != '\0')
	{
		while (*t != '%' && *t != '\0')
		{
			_putchar(*t);
			t++;
			count++;
		}
		if (*t == '\0')
			break;
		t++;
		if (*t == 'c')
			print_char(args, &count);
		else if (*t == 's')
			print_string(args, &count);
		else if (*t == '%')
			print_percent(&count);
		else if (*t == 'd' || *t == 'i')
			print_int(args, &count);
		else
		{
			_putchar('%');
			_putchar(*t);
			count += 2;
		}
		t++;
	}
	va_end(args);
	return (count);
}
