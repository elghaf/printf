#include <stdarg.h>
#include "main.h"

/**
 * print_single_char - Print a single character
 * @args: A va_list containing the character to be printed
 *
 * Return: The number of characters printed (always 1)
 */
int print_single_char(va_list args)
{
	char character = (char)va_arg(args, int);

	_putchar(character);
	return (1);
}

/**
 * print_string - Print a string of characters
 * @args: A va_list containing the string to be printed
 *
 * Return: The number of characters printed
 */
int print_string(va_list args)
{
	const char *str = va_arg(args, const char *);
	int index = 0, len_of_our_string;

	if (str == NULL)
		str = "(null)";

	len_of_our_string = strlen(str);
	while (index < len_of_our_string)
	{
		/* code */
		_putchar(str[index]);
		index++;
	}

	return (len_of_our_string);
}

/**
 * print_integer - Print an integer
 * @args: A va_list containing the integer to be printed
 *
 * Return: The number of characters printed
 */
int print_integer(va_list args)
{
	int number = va_arg(args, int);
	int is_negative = 0;
	int character_count = 0;
	int divisor = 1;
	int temp = number;

	if (number < 0)
	{
		_putchar('-');
		character_count++;
		is_negative = 1;
		number = -number;
	}

	while (temp > 9)
	{
		divisor *= 10;
		temp /= 10;
	}

	while (divisor > 0)
	{
		int digit = number / divisor;
		_putchar('0' + digit);
		character_count++;
		number %= divisor;
		divisor /= 10;
	}

	return (character_count + is_negative);
}

/**
 * print_unsigned_integer - Print an unsigned integer
 * @args: A va_list containing the unsigned integer to be printed
 *
 * Return: The number of characters printed
 */
int print_unsigned_integer(va_list args)
{
	unsigned int number = va_arg(args, unsigned int);
	unsigned int divisor = 1;
	unsigned int temp = number;
	int character_count = 0;
	unsigned int  digit;

	while (temp > 9)
	{
		divisor *= 10;
		temp /= 10;
	}

	while (divisor > 0)
	{
		digit = number / divisor;
		_putchar('0' + digit);
		character_count++;
		number %= divisor;
		divisor /= 10;
	}

	return (character_count);
}

/**
 * print_octal_integer - Print an unsigned integer in octal format
 * @args: A va_list containing the unsigned integer to be printed
 *
 * Return: The number of characters printed
 */
int print_octal_integer(va_list args)
{
	unsigned int number = va_arg(args, unsigned int);
	unsigned int octal_digits[100];
	int octal_count = 0;
	int character_count = 0;
	int i;

	if (number == 0)
	{
		_putchar('0');
		character_count++;
	}
	else
	{
		while (number > 0)
		{
			octal_digits[octal_count++] = number % 8;
			number /= 8;
		}

		for (i = octal_count - 1; i >= 0; i--)
		{
			_putchar('0' + octal_digits[i]);
			character_count++;
		}
	}

	return (character_count);
}

/**
 * print_hexadecimal - Print an unsigned integer in hexadecimal format
 * @args: A va_list containing the unsigned integer to be printed
 *
 * Return: The number of characters printed
 */
int print_hexadecimal(va_list args)
{
	unsigned int number = va_arg(args, unsigned int);
	char hex_digits[] = "0123456789abcdef";
	int hex_count = 0;
	char buffer[100];
	int character_count = 0;
	int i;
	char digit;

	if (number == 0)
	{
		_putchar('0');
		character_count++;
	}
	else
	{
		while (number > 0)
		{
			buffer[hex_count++] = hex_digits[number % 16];
			number /= 16;
		}

		for (i = hex_count - 1; i >= 0; i--)
		{
			digit = buffer[i];
			_putchar(digit);
			character_count++;
		}
	}

	return (character_count);
}

/**
 * print_hexadecimal_uppercase - Print an unsigned integer in uppercase hexadecimal format
 * @args: A va_list containing the unsigned integer to be printed
 *
 * Return: The number of characters printed
 */
int print_hexadecimal_uppercase(va_list args)
{
	unsigned int number = va_arg(args, unsigned int);
	char hex_digits[] = "0123456789ABCDEF";
	int hex_count = 0;
	char buffer[100];
	int character_count = 0;
	int i;

	if (number == 0)
	{
		_putchar('0');
		character_count++;
	}
	else
	{
		while (number > 0)
		{
			buffer[hex_count++] = hex_digits[number % 16];
			number /= 16;
		}

		for (i = hex_count - 1; i >= 0; i--)
		{
			char digit = buffer[i];
			_putchar(digit);
			character_count++;
		}
	}

	return (character_count);
}
