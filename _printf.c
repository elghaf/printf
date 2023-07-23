#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <string.h>

/**
 * _printf - Custom implementation of printf with limited conversion specifiers.
 * @format: The format string containing zero or more directives.
 *
 * This function parses the format string and handles the conversion specifiers:
 * 'c' - for printing characters.
 * 's' - for printing strings.
 * '%' - for printing the '%' character.
 *
 * Return: The number of characters printed (excluding the null byte used to end
 * output to strings).
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int chars_printed = 0;
    char c;
    while ((c = *format++))
    {
        if (c == '%')
        {
            // Get the next character after '%'
            c = *format++;
            switch (c)
            {
                case 'c':
                    // Print a character
                    putchar(va_arg(args, int));
                    chars_printed++;
                    break;
                case 's':
                {
                    // Print a string
                    const char *str = va_arg(args, const char*);
                    while (*str)
                    {
                        putchar(*str++);
                        chars_printed++;
                    }
                    break;
                }
                case '%':
                    // Print '%'
                    putchar('%');
                    chars_printed++;
                    break;
                default:
                    // Invalid conversion specifier, ignore and continue
                    break;
            }
        }
        else
        {
            // Regular character, just print it
            putchar(c);
            chars_printed++;
        }
    }

    va_end(args);
    return chars_printed;
}
