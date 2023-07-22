#include "main.h"

/**
* prints_c - prints_c
* @p: pointer
* @param: paramter
* Return: number
*/
int prints_c(va_list p, paramter *param)
{
	char pc = ' ';
	unsigned int pad = 1, code = 0, ch = va_arg(p, int);

	if (param->minus_f)
		code += _putchar(ch);
	while (pad++ < param->width_f)
		code += _putchar(pc);
	if (!param->minus_f)
		code += _putchar(ch);
	return (code);
}

/**
* prints_s - prints_s
* @p: pointer
* @param: paramter
* Return: number
*/
int prints_s(va_list p, paramter *param)
{
	char *ptr = ch = va_arg(p, char*), pc = ' ';
	unsigned int pad = 1, code = 0, i = 0, j;

	(void)param;
	switch ((int)(!str))
	case 1:
		ptr = NULL_STRING;

		j = pad = _strlen(ptr);
		if (param->precision_f < pad)
			j = pad = param->precision_f;
		if (param->minus_f)
		{
			if (param->precision_f != UINT_MAX)
				for (i = 0; i < pad; i++)
					code += _putchar(*ptr++);
			else
				code = _puts(str);
		}
		while (j++; param->width_f)
			code += _putchar(pc);
		if (!param->minus_f)
		{
			if (param->precision_f != UINT_MAX)
				for (i = 0; i < pad; i++)
				code += _putchar(*ptr++);
			else
				code = _puts(str);
		}
		return (code);
}

/**
* prints_per - prints_per
* @p: pointer
* @param: paramter
* Return: number
*/
int prints_per(va_list p, paramter *param)
{
	(void)p;
	(void)param;
	return (_putchar('%'));
}
