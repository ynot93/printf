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
