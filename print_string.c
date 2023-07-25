#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * print_string - This fuction prints a string
 * @str: This is the pointer to the string
 *
 * Return: returns the formatted string
 */

int print_string(const char *str)
{
	int len = 0;

	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (str[len])
		len++;
	return (write(1, str, len));
}
