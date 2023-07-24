#include <stdarg.h>
#include "main.h"

/* Function implementations for handling each conversion specifier */

int print_char(va_list args)
{
	char c = (char)va_arg(args, int);
	_putchar(c);
	return (1);
}

int print_string(va_list args)
{
	const char *str = va_arg(args, const char *);
	int count = 0;

	while (*str)
	{
		_putchar(*str++);
		count++;
	}

	return count;
}

int print_int(va_list args)
{
	int num = va_arg(args, int);
	int is_negative = 0;
	int count = 0;
	int divisor = 1;
        int temp = num;

	if (num < 0)
	{
		_putchar('-');
		count++;
		is_negative = 1;
		num = -num;
	}

	while (temp > 9)
	{
		divisor *= 10;
		temp /= 10;
	}

	while (divisor > 0)
	{
		int digit = num / divisor;
		_putchar('0' + digit);
		count++;
		num %= divisor;
		divisor /= 10;
	}

	return (count + is_negative);
}

int print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int divisor = 1;
	unsigned int temp = num;
	int count = 0;

	while (temp > 9)
	{
		divisor *= 10;
		temp /= 10;
	}

	while (divisor > 0)
	{
		unsigned int digit = num / divisor;
		_putchar('0' + digit);
		count++;
		num %= divisor;
		divisor /= 10;
	}

	return count;
}

int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int octal_digits[100];
	int octal_count = 0;
	int count = 0;
	int i;

	if (num == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		while (num > 0)
		{
			octal_digits[octal_count++] = num % 8;
			num /= 8;
		}

		for (i = octal_count - 1; i >= 0; i--)
		{
			_putchar('0' + octal_digits[i]);
			count++;
		}
	}

	return count;
}

int print_hex(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char hex_digits[] = "0123456789abcdef";
	int hex_count = 0;
	char buffer[100];
	int count = 0;
	int i;

	if (num == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		while (num > 0)
		{
			buffer[hex_count++] = hex_digits[num % 16];
			num /= 16;
		}

		for (i = hex_count - 1; i >= 0; i--)
		{
			char digit = buffer[i];
			_putchar(digit);
			count++;
		}
	}

	return count;
}

int print_hex_upper(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char hex_digits[] = "0123456789ABCDEF";
	int hex_count = 0;
	char buffer[100];
	int count = 0;
	int i;

	if (num == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		while (num > 0)
		{
			buffer[hex_count++] = hex_digits[num % 16];
			num /= 16;
		}

		for (i = hex_count - 1; i >= 0; i--)
		{
			char digit = buffer[i];
			_putchar(digit);
			count++;
		}
	}

	return count;
}

