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

/**
 * print_binary - print an unsigned int as binary
 * @args: the va_list containing the number to print
 *
 * Return: the number of characters printed
 */
int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int len = 0;
	int i;
	char buffer[32];

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	for (i = 0; i < 32; i++)
		buffer[i] = (num >> (31 - i) & 1) + '0';

	for (i = 0; i < 32; i++)
	{
		if (buffer[i] == '1')
			break;
	}

	for (; i < 32; i++)
	{
		_putchar(buffer[i]);
		len++;
	}

	return (len);
}
