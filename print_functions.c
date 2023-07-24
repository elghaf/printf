#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * _print_char - Handle the conversion specifer c
 * @c: A character
 * @s: A pointer to a string
 * @n: An integer
 *
 * Return: 1 or -1 if it fails.
 */
int _print_char(__attribute__((unused)) char c,
__attribute__((unused)) const char *s, __attribute__((unused)) int n)
{
	return (_putchar(c));
}

/**
 * _print_string - Handle the conversion specifer s
 * @c: A character
 * @s: A pointer to a string
 * @n: An integer
 *
 * Return: The length of the string or -1 if it fails.
 */
int _print_string(__attribute__((unused)) char c,
__attribute__((unused)) const char *s, __attribute__((unused)) int n)
{
	return (_puts(s));
}
/**
 * _print_int - handle the conversion specifiers related to numbers
 * @c: A character
 * @s: A pointer to a string
 * @n: An integer
 *
 * Return: The number of bytes printed or - 1 if it fails.
 */
int _print_int(__attribute__((unused)) char c,
__attribute__((unused)) const char *s, __attribute__((unused)) int n)
{
	int k;

	if (c == 'b')
		k = print_binary(n);
	return (k);
}
