#include "main.h"

/**
 * _print_char - Custom printf function to handle characters.
 * @args: List of arguments.
 *
 * Return: The number of characters printed.
 */
int _print_char(va_list args)
{
	putchar(va_arg(args, int));
	return (1);
}
/**
 * handle_binary - converts integer to binary number
 * @args: list of arguments.
 *
 * Return: The number of characters
 */
int handle_binary(va_list args)
{
	int number = va_arg(args, int);
	int count = 0;
	int binary[32];
	int num_bits = 0;

	do {
		binary[num_bits++] = number % 2;
		number /= 2;
	} while (number > 0);

	while (num_bits > 0)
	{
		num_bits--;
		putchar(binary[num_bits] + '0');
		count++;
	}

	return (count);
}
