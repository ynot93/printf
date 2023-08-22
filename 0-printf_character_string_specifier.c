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
	int count;
	const char *str;

	va_start(args, format);
	count = 0;

	while (*format != '\0' && format != NULL)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int)), count++;
					break;
				case 's':
					str = va_arg(args, const char *);
					while (*str != '\0' && str != NULL)
					{
						putchar(*str), count++, str++;
					}
					break;
				case '%':
					putchar('%'), count++;
					break;
				default:
					putchar('%'), putchar(*format), count += 2;
					break;
			}
		}
		else
		{
			putchar(*format), count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
