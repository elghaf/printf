#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"
/**
 * print_int - The function print integer.
 *@integer_print: The integer to be printed
 *@neg_pos: The negative or positve sign
 *@integer_space: the integer space
 *
 *Return: Return index_counter.
 */

int print_int(int integer_print, char neg_pos, char integer_space)
{
	int index_counter = 0;
	char buffer[12];
	int len = 0;

	if (integer_print == INT_MIN)
	{
		index_counter += write(1, "-2147483648", 11);
		return (index_counter);
	}

	if (integer_print < 0)
	{
	    index_counter += write(1, "-", 1);
	    integer_print = -integer_print;
	}
	else if (neg_pos)
	{
	    index_counter += write(1, "+", 1);
	}
	else if (integer_space)
	{
	    index_counter += write(1, " ", 1);
	}
	else if (integer_print == 0)
	{
	    index_counter += write(1, "0", 1);
	    return index_counter;
	}
	while (integer_print > 0)
	{
		buffer[len++] = '0' + integer_print % 10;
		integer_print /= 10;
	}
	while (len > 0)
		index_counter += write(1, &buffer[--len], 1);
	return (index_counter);
}
