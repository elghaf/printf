#include "main.h"

/**
 * _putchar - it print each char
 * @c: charecter to print
 * Return: the cprinted char
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
