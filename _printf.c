#include <stdarg.h>
#include "main.h"
#include <string.h>

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

/**
 * print_string - Prints a string
 * @str: The string to be printed
 * Return: Number of characters printed
 */

int print_string(const char *str)
{
    int index = 0, len_of_our_string;

    if (str == NULL)
        str = "(null)";

    len_of_our_string = strlen(str);
    while (index < len_of_our_string)
    {
        /* code */
        m_putchars(str[index]);
        index++;
    }

    return (len_of_our_string);
}

/**
 * process_format - Processes the format string and prints accordingly
 * @format: The format string
 * @args: The va_list containing arguments
 * Return: Total number of characters printed
 */

int process_format(const char *format, va_list my_args)
{
    int count = 0;
    char buffer[20];
    char *s;
    int num, len, i;

    while (*format)
    {
        if (*format != '%')
        {
            m_putchars(*format);
            count++;
        }
        else
        {
            format++;
            switch (*format)
            {
            case 'c':
                m_putchars(va_arg(my_args, int));
                count++;
                break;
            case 's':
                s = va_arg(my_args, char *);
                len = 0;
                while (s[len])
                    len++;
                count += len;
                fputs(s, stdout);
                break;
            case 'd':
            case 'i':
                num = va_arg(my_args, int);
                if (num < 0)
                {
                    m_putchars('-');
                    count++;
                    num = -num;
                }
                len = 0;
                do {
                    buffer[len++] = num % 10 + '0';
                    num /= 10;
                } while (num > 0);
                for (i = len - 1; i >= 0; i--)
                {
                    m_putchars(buffer[i]);
                }
                count += len;
                break;
            default:
                m_putchars('%');
                m_putchars(*format);
                count += 2;
                break;
            }
        }
        format++;
    }
    return (count);
}

/**
 * _printf - Prints formatted output
 * @format: The format string
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
    va_list args;
    int total_count;

    va_start(args, format);

    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
    {
        va_end(args);
        return (-1);
    }

    if (strcmp(format, "% ") == 0 || strcmp(format, "%") == 0)
    {
        va_end(args);
        return (-1);
    }

    total_count = process_format(format, args);

    va_end(args);
    return (total_count);
}
