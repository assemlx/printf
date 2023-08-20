#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * print_number - print an integer number
 * @args: the va_list containing the number to print
 *
 * Return: the number of characters printed
 */
int print_number(va_list args)
{
	int num = va_arg(args, int);
	int len = 0;
	int divisor = 1;
	char buffer[20];

	if (num < 0)
	{
		_putchar('-');
		len++;
		num *= -1;
	}

	while (num / divisor > 9)
		divisor *= 10;

	while (divisor > 0)
	{
		buffer[len] = (num / divisor) + '0';
		_putchar(buffer[len]);
		len++;
		num %= divisor;
		divisor /= 10;
	}

	return (len);
}
