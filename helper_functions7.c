#include "main.h"

/**
 * handle_p - Handles printing pointers.
 * @args: List of arguments.
 *
 * Return: The number of characters printed.
 */
int handle_p(va_list args)
{
	void *ptr;
	int count;
	unsigned long int value;
	int num_digits;
	unsigned long int temp;
	
	char hex_digits[] = "0123456789abcdef";
	ptr = va_arg(args, void *);
	count = 0;
	num_digits = 0;
	
	putchar('0');
	putchar('x');
	count += 2;

	value = (unsigned long int)ptr;
	temp = value;
	
	do {
		num_digits++;
		temp /= 16;
	} while (temp != 0);

	while (num_digits > 0)
	{
		num_digits--;
		putchar(hex_digits[(value >> (num_digits * 4)) & 0xF]);
		count++;
	}
	return (count);
}
