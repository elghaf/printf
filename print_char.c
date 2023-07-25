#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
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
