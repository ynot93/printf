#include "main.h"
/**
 * handle_o - converts int to a string in base 8
 * @args: List of arguments
 *
 * Return: count of characters
 */
int handle_o(va_list args)
{	
	unsigned int number;
	int count;

	number = va_arg(args, unsigned int);
	count = 0;
	
	if (number == 0)
	{
		putchar('0');
		count++;
	}
	else
	{
		char buffer[20];
		int length = 0;

		while (number > 0)
		{
			buffer[length++] = (number % 8) + '0';
			number /= 8;
		}

		while (length > 0)
		{
			length--;
			putchar(buffer[length]);
			count++;
		}
	}
	
	return (count);
}
