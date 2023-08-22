#include "main.h"

/**
 * dispatcher - Handles the edge cases of the printf function.
 * @specifier: Condition for handling the specifiers.
 * @args: List of arguments.
 *
 * Return: Nothing.
 */
int dispatcher(const char specifier, va_list args)
{
	switch (specifier)
	{
		case 'c':
			return (_print_char(args));
		case 's':
			return (_print_string(args));
		case 'd':
		case 'i':
			return (_print_int(args));
		case 'b':
			return (handle_binary(args));
		case 'u':
			return (handle_u(args));
		case 'o':
			return (handle_o(args));
		case '%':
			putchar('%');
			return (1);
		default:
			putchar('%');
			putchar(specifier);
			return (2);
	}
}
