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
	int count, buffer_index, i;
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
			for (i = 0; i < buffer_index; i++)
				putchar(buffer[i]);
			buffer_index = 0;
		}
		format++;
	}
	if (buffer_index > 0)
	{
		for (i = 0; i < buffer_index; i++)
			putchar(buffer[i]);
	}
	va_end(args);
	return (count);
}
