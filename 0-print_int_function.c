#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"

/**
 * print_integer_space - The function prints an integer.
 * @integer_print: The numb integer that need to be printe.
 * @neg_pos: The negative or positive sign ('-' for negative, '+' for positive)
 * @integer_space: The integer space.
 *
 * Return: The index_counter.
 */

int print_integer_space(int integer_print, char neg_pos, char integer_space)
{
	int index_counter = 0;
	int string_len = 0, i = 0;
	char character[12];

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
		character[string_len] = '0' + integer_print % 10;
		integer_print /= 10;
		i++;
		string_len++;
	}
	while (string_len > 0)
		index_counter = index_counter + write(1, &character[--string_len], 1);
	return (index_counter);
}
