#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"
/**
 * print_int - The function print integer.
 *@num: The integer to be printed
 *@sign: The sign of the integer
 *@space: The space between the integer
 *
 *Return: Return index_counter.
 */

int print_int(int num, char sign, char space)
{
	int index_counter = 0;
	char buffer[12];
	int len = 0;

	if (num == INT_MIN)
	{
		index_counter += write(1, "-2147483648", 11);
		return (index_counter);
	}

	if (num < 0)
	{
		index_counter += write(1, "-", 1);
		num = -num;
	} else if (sign)
	{
		index_counter += write(1, "+", 1);
	} else if (space)
	{
		index_counter += write(1, " ", 1);
	}
	else if (num == 0)
	{
		index_counter += write(1, "0", 1);
		return (index_counter);
	}

	do {
		buffer[len++] = '0' + num % 10;
		num /= 10;
	} while (num > 0);

	while (len > 0)
		index_counter += write(1, &buffer[--len], 1);

	return (index_counter);
}
