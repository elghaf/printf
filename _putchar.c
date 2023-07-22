#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char bufer[OUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUT_BUF_SIZE)
	{
		write(1, bufer, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		bufer[i++];
	return (1);
}
