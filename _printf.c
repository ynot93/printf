#include "main.h"
/**
 * _printf - Function that executes printf.
 * @format: String to be formatted.
 *
 * Return: The number of characters.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;

	va_start(args, format);
	count = 0;

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			count++;
		}
		else
		{
			format++;
			count += dispatcher(*format, args);
		}
		format++;
	}
	va_end(args);
	return (count);
}
