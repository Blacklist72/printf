#include "main.h"

/**
 * print_int - Print int
 * @types: arguments list
 * @buffer: array to handle print
 * @flags:  active flag
 * @width: get width.
 * @precision: specifier
 * @size: specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFFR_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_number_size(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFFR_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	return (write_number_handler(is_negative, i,
		buffer, flags, width, precision, size));
}
/**
 * str_print - Prints a string
 * @types: List of arguments
 * @buffer: array to handle print
 * @flags:  active flag
 * @width: width.
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of chars printed
 */
int str_print(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	NOT_USED(buffer);
	NOT_USED(flags);
	NOT_USED(width);
	NOT_USED(precision);
	NOT_USED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
		{
			str = " ";
		}
	}
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & FLAG_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * percent_print - Prints percent sign
 * @types: argument list
 * @buffer: array to handle print
 * @flags:  active flag
 * @width: get width.
 * @precision: Precision
 * @size: specifier
 * Return: Number of chars printed
 */
int percent_print(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	NOT_USED(types);
	NOT_USED(buffer);
	NOT_USED(flags);
	NOT_USED(width);
	NOT_USED(precision);
	NOT_USED(size);
	return (write(1, "%%", 1));
}

/**
 * bin_print - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: array to handle print
 * @flags:  active flag
 * @width: get width.
 * @precision: specifier
 * @size: specifier
 * Return: Numbers of char printed.
 */
int bin_print(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	NOT_USED(buffer);
	NOT_USED(flags);
	NOT_USED(width);
	NOT_USED(precision);
	NOT_USED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  gets active flag
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (write_char_handler(c, buffer, flags, width, precision, size));
}
