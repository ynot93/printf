#include "main.h"

/**
 * handle_S - Handles custom string printing.
 * @args - List of arguments.
 * 
 * Return - Number of characters printed.
 */
int handle_S(va_list args)
{
	const char *str;
	int count;
	char hex_digits[] = "0123456789ABCDEF";

	str = va_arg(args, const char *);
	count = 0;

	while (*str != '\0')
	{
		if (*str >= 32 && *str < 127)
		{
			putchar(*str);
			count++;
		}
		else
		{
			putchar('\\');
			putchar('x');
			putchar(hex_digits[(*str >> 4) & 0xF]);
			putchar(hex_digits[*str & 0xF]);
			count += 4;
		}
		str++;
	}
	return (count);
}
