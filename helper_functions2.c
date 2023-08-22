#include "main.h"

/**
 * handle_u - Handles unsigned integers
 * @args: list of arguments
 *
 * Return: number of characters
 */
int handle_u(va_list args)
{
	unsigned int number = va_arg(args, unsigned int);
	int count = 0;

	if (number == 0)
	{
		putchar('0');
		count++;
	}
	else
	{
		char buffer[20];
		int length = 0;

		while(number > 0)
		{
			buffer[length++] = (number % 10) + '0';
			number /= 10;
		}

		while (length > 0)
		{
			length--;
			putchar(buffer[length]);
			 count++;
		}
	}
	
	return count;
} 
