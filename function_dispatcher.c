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
			break;
		case 's':
			return (_print_string(args));
			break;
		case 'd':
		case 'i':
			return (_print_int(args));
			break;
		case 'b':
			return (handle_binary(args));
			break;
		case 'u':
			return (handle_u(args));
			break;
		case '%':
			putchar('%');
			return (1);
			break;
		default:
			putchar('%');
			putchar(specifier);
			return (2);
			break;
	}
}
