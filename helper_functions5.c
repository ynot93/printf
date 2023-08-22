#include "main.h"

/**
 * handle_x - converts string to uppercase hexadecimal
 * @args: list of arguments
 *
 * Return:count of characters
 */
int handle_X(va_list args)
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
			int digit = number % 16;
			if (digit < 10)
				buffer[length++] = digit + '0';
			 else
				 buffer[length++] = digit - 10 + 'A';

			 number /= 16;
		}
		
		while(length > 0)
		{
			length--;
			putchar(buffer[length]);
			count++;
		}
	}

	return (count);
}
