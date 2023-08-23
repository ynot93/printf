#include "main.h"
/**
 * _printf-function that executes printf
 * @format: string to be formatted
 *
 * Return: the number of characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count, buffer_index;
	char buffer[BUFFER_SIZE];

	va_start(args, format);
	count = 0;
	buffer_index = 0;

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += dispatcher(*format, args);
		}
		else
		{
			buffer[buffer_index++] = *format;
			count++;
		}
		if (buffer_index >= BUFFER_SIZE - 1)
		{
			write(1, buffer, buffer_index);
			buffer_index = 0;
		}
		format++;
	}
	if (buffer_index > 0)
		write(1, buffer, buffer_index);

	va_end(args);
	return (count);
}
