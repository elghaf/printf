#include <unistd.h>
#include "main.h"

/**
 * my_putchar - writes the character c to stdout
 * @character: The character to print
 *
 * Return: On success return 1.
 * On error, return -1.
 */
int m_putchar(char character)
{
	return (write(1, &character, 1));
}
