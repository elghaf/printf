#include "main.h"

/**
 * p - write to the console
 * @c: character
 * Return: nothing
 */
void p(char c)
{
char *pc = &c;
write(STDOUT_FILENO, pc, sizeof(c));
}
/**
 * ps - write to the console
 * @s: string
 * Return: nothing
 */
void ps(char *s)
{
write(STDOUT_FILENO, s, strlen(s));
}
/**
 * _printf - print to the console
 * @format: specifier
 * Return: integer
 */
int _printf(const char *format, ...)
{
int i = 0;
int j = 0;
va_list args;
va_start(args, format);
while (format[i] && format != NULL)
{
switch (format[i])
{
case 'c':
{
int x = va_arg(args, int);
p(x);
break;
}
case 's':
{
char *x = va_arg(args, char *);
if (x == NULL)
{
write(STDOUT_FILENO, "(nil)", 5);
break;
}
ps(x);
break;
}
case '%':
{
char *s = "%";
write(STDOUT_FILENO, s, 1);
break;
}
default:
{
i++;
continue;
}
}
i++;
}
va_end(args);
return (j);
}
