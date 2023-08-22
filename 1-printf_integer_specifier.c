#include "main.h"
/**
 * _printf - Custom printf function to handle nummbers
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count, length, number;
	char string[100];

	count = 0, length = 0, va_start(args, format);

	while (*format && format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'd':
				case 'i':
					number = va_arg(args, int);
					if (number < 0)
						write(1, "-", 1), number = -number, count++;
					do {
						string[length++] = number % 10 + '0', number /= 10;
					} while (number);
					while (length > 0)
						length--, write(1, &string[length], 1), count++;
					break;
				case '%':
					write(1, "%", 1), count++;
					break;

				default:
					write(1, format - 1, 2), count += 2;
					break;
			}
		}
		else
			write(1, format, 1), count++;
		format++;
	}
	va_end(args);
	return (count);
}
