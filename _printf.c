#include "main.h"

/**
 * _printf - function that produces output according to a format.
 * @format: string.
 *
 * Return: the number of characters printed,
 *(excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int code = 0;
	va_list p;
	char *pt, *first;
	paramter param = PARAM;

	va_start(p, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (!format || (format[0] == ' ' && !format[2]))
		return (-1);

	for (pt == (char *)format; *pt; pt++)
	{
		first = pt;
		pt++;
	}

	_putchar(BUF_FLUSH);
	va_end(p);
	return (code);
}
