#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"

/**
 * print_numbers - The function prints an integer.
 * @integer_print: The numb integer that need to be printe.
 * @neg_pos: The negative or positive sign ('-' for negative, '+' for positive)
 * @integer_space: The integer space.
 *
 * Return: The index_counter.
 */

int print_numbers(int integer_print, char neg_pos, char integer_space)
{
	int index_counter = 0;
	int result_int;
	int string_len = 0, i = 0;
	char character[12];

	result_int = integer_print;
	if (result_int == INT_MIN)
	{
		i++;
		index_counter = index_counter + write(1, "-2147483648", 11);
		return (index_counter);
	}
	if (result_int < 0)
	{
		index_counter = index_counter + write(1, "-", 1);
		i++;
		result_int = -integer_print;
	}
	if (neg_pos)
	{
		index_counter = index_counter + write(1, "+", 1);
	}
	if (result_int == 0)
	{
		index_counter = index_counter + write(1, "0", 1);
		return (index_counter);
	}
	if (result_int)
	{
		index_counter = index_counter + write(1, " ", 1);
	}

	while (result_int > 0)
	{
		character[string_len] = '0' + result_int % 10;
		result_int = result_int / 10;
		i++;
		string_len++;
	}
	while (string_len > 0)
		index_counter = index_counter + write(1, &character[--string_len], 1);
	return (index_counter);
}
