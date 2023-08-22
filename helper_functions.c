#include "main.h"
/**
 * _print_int - Custom printf function to handle nummbers.
 * @args: List of arguments.
 *
 * Return: The number of characters printed.
 */
int _print_int(va_list args)
{
	int count, length, number;
	int digits[10];

	count = 0;
	length = 0;
	number = va_arg(args, int);

	if (number < 0)
	{
		putchar('-');
		number = -number;
		count++;
	}
	do {
		digits[length++] = number % 10;
		number /= 10;
	} while (number);
	while (length > 0)
	{
		length--;
		putchar(digits[length] + '0');
		count++;
	}
	return (count);
}

/**
 * _print_string - Custom function to handle strings.
 * @args: List of arguments.
 *
 * Return: The number of characters printed.
 */
int _print_string(va_list args)
{
	const char *str;
	int count;

	count = 0;
	str = va_arg(args, const char *);

	while (*str != '\0' && str != NULL)
	{
		putchar(*str), count++, str++;
	}
	return (count);
}
