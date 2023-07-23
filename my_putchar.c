#include <unistd.h>
#include "main.h"

/**
 * my_putchar - Writes a character to the standard output (stdout)
 * @c: The character to be printed
 *
 * Return: On success, the number of characters written (1).
 *         On error, -1 is returned, and errno is set appropriately.
 */
int my_putchar(char c)
{
	return (write(1, &c, 1));
}
