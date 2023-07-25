#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_char - This function prints character
 * @c: The character itself
 *
 * Return: returns the character passed
 */

int print_char(int c)
{
	return (write(1, &c, 1));
}
