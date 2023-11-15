#include "main.h"

/**
 * reverse_str - reverse string.
 * @types: argument list
 * @buffer: array to handle print
 * @flags:  active flag
 * @width: get width
 * @precision: specifier
 * @size: specifier
 * Return: int Numbers of chars printed
 */

int reverse_str(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	NOT_USED(buffer);
	NOT_USED(flags);
	NOT_USED(width);
	NOT_USED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		NOT_USED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * non_printable_char_print - Prints ascii codes in hexa of non printable chars
 * @types: argument list
 * @buffer: array to handle print
 * @flags:  active flag
 * @width: get width
 * @precision: specifier
 * @size: specifier
 * Return: int no of chars printed
 */
int non_printable_char_print(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	NOT_USED(flags);
	NOT_USED(width);
	NOT_USED(precision);
	NOT_USED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (check_if_printatble(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code_util(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**
 * rot13_str - Print a string in rot13.
 * @types: arguments list
 * @buffer: array to handle print
 * @flags:  active flag
 * @width: get width
 * @precision: specifier
 * @size: specifier
 * Return: int Numbers of chars printed
 */
int rot13_str(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	NOT_USED(buffer);
	NOT_USED(flags);
	NOT_USED(width);
	NOT_USED(precision);
	NOT_USED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

/**
 * _putchar - write character c to the stdout
 * @c: the character
 * Return: 1 on success and -1 otherwise
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_ptr - Prints the value of a pointer
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: integer No of chars printed.
 */
int print_ptr(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFFR_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	NOT_USED(width);
	NOT_USED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFR_SIZE - 1] = '\0';
	NOT_USED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS))
		padd = '0';
	if (flags & FLAG_PLUS)
		extra_c = '+', length++;
	else if (flags & FLAG_SPACE)
		extra_c = ' ', length++;

	ind++;

	return (write_pointer_handler(buffer, ind, length,
				width, flags, padd, extra_c, padd_start));
}
