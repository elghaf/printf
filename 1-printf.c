#include "main.h"

/**
 * _printf - Printf functions.
 * @format: is a character string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int result_sum = 0;
	va_list var_list;
	char *ch, *st;

	params_t parameter = PARAMS_INIT;
	var_start(var_list, format);
	if ((!format || (format[0] == '%' && !format[1])) || (format[0] == '%' && format[1] == ' ' && !format[2]))
	return (-1);
	ch = (char *)format;
	for (ch ; *ch; ch++)
	{
		init_params(&parameter, var_start);
		if (*ch != '%')/*checking for the % specifier*/
		{
			result_sum += _putchar(*ch);
			continue;
		}
		st = ch;
		ch++;
		while (get_flag(ch, &parameter)) /* while char at p is flag character */
		{
			ch++; /* next character */
		}
		ch = get_width(ch, &parameter, var_start);
		ch = get_precision(ch, &parameter, var_start);
		if (get_modifier(ch, &parameter))
			ch++;
		if (!get_specifier(ch))
			result_sum += print_from_to(st, ch,
					parameter.l_modifier || parameter.h_modifier ? ch - 1 : 0);
		else
			result_sum += get_print_func(ch, var_start, &parameter);
	}
_putchar(BUF_FLUSH);
va_end(var_list);
return (result_sum);
}
