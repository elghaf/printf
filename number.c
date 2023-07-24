#include "main.h"

/**
 * print_binary - Handle the conversion specifier b
 * @n: The input unsigned int
 *
 * The function converts the unsigned argument to binary
 *
 * Return: The number of bytes printed.
 */
int print_binary(unsigned int n)
{
	static int count = 0;
	
	if (n == 0 && count == 0)
	{
		_putchar('0');
		return (1);
	}
	if (n / 2 == 0 && n % 2 == 0)
	{
		return (0);
	}

	count++;
	print_binary(n / 2);	
	_putchar('0' + n % 2);
	return (count);
}
