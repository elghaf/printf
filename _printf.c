#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - Prints a single character
 * @c: The character to be printed
 * Return: Number of characters printed (always 1)
 */

int print_char(char c)
{
	char character;

	character = c;
	m_putchars(character);
	return (1);
}


int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            m_putchar(*format);
            count++;
        }
        else
        {
            format++; // Move past the '%'
            if (*format == '\0') // If '%' is the last character, stop
                break;

            if (*format == '%') // Print a literal '%'
            {
                m_putchar('%');
                count++;
            }
            else if (*format == 'c') // Print a character
            {
                char c = (char)va_arg(args, int);
                m_putchar(c);
                count++;
            }
            else if (*format == 's') // Print a string
            {
                char *str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";

                while (*str)
                {
                    m_putchar(*str);
                    str++;
                    count++;
                }
            }
            else if (*format == 'd' || *format == 'i') // Print a decimal integer
            {
                int num = va_arg(args, int);
                int temp = num;
                int digits = 0;

                if (num == 0) // Special case for 0
                {
                    m_putchar('0');
                    count++;
                }
                else if (num < 0) // Handle negative numbers
                {
                    m_putchar('-');
                    count++;

                    // Convert negative number to positive for easier handling
                    num = -num;
                    temp = num;
                }

                // Count the number of digits in the integer
                while (temp > 0)
                {
                    temp /= 10;
                    digits++;
                }

                // Print each digit of the integer
                for (int i = 0; i < digits; i++)
                {
                    int divisor = 1;
                    for (int j = i + 1; j < digits; j++)
                        divisor *= 10;

                    int digit = num / divisor;
                    m_putchar('0' + digit);
                    count++;

                    num %= divisor;
                }
            }
            else // Unsupported specifier, print it as is
            {
                m_putchar('%');
                m_putchar(*format);
                count += 2;
            }
        }

        format++; // Move to the next character
    }

    va_end(args);
    return (count);
}
