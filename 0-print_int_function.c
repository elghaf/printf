#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"
/**
 * print_int - The function prints an integer.
 * @integer_print: The integer to be printed
 * @neg_pos: The negative or positive sign ('-' for negative, '+' for positive)
 * @integer_space: The integer space (number of digits)
 *
 * Return: The index_counter.
 */

int print_int(int integer_print, char neg_pos, char integer_space)
{
	int index_counter = 0;
	char buffer[12];
	int string_len = 0, i = 0;

	if (integer_print == INT_MIN)
	{
		i++;
		index_counter = index_counter + write(1, "-2147483648", 11);
		return (index_counter);
	}
	if (integer_print < 0)
	{
		index_counter = index_counter + write(1, "-", 1);
		i++;
		integer_print = -integer_print;
	} else if (neg_pos)
	{
		index_counter = index_counter + write(1, "+", 1);
	} else if (integer_print == 0)
	{
		index_counter = index_counter + write(1, "0", 1);
		return (index_counter);
	} else if (integer_space)
	{
		index_counter = index_counter + write(1, " ", 1);
	}

	while (integer_print > 0)
	{
		buffer[string_len] = '0' + integer_print % 10;
		integer_print /= 10;
		i++;
		string_len++;
	}
	while (string_len > 0)
		index_counter = index_counter + write(1, &buffer[--string_len], 1);
	return (index_counter);
}
