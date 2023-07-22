#include "main.h"

/**
 * _puts - print string.
 * @st: input
 * Return: void
 */
int _puts(char *st)
{
	char c = st;

	while (*st)
		_putchar(*st++);
	return (st - c);
}
