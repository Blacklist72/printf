#include "main.h"

/**
 * convert_unsgned_size - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_unsgned_size(unsigned long int num, int size)
{
	if (size == SIZE_L)
		return (num);
	else if (size == SIZE_S)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

/**
 * append_hexa_code_util - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code_util(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_number_size - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_number_size(long int num, int size)
{
	if (size == SIZE_L)
		return (num);
	else if (size == SIZE_S)
		return ((short)num);

	return ((int)num);
}

/**
 * check_if_printatble - Evaluates if a char is printable
 * @c: Char to be evaluated.
 * Return: 1 if c is printable, 0 otherwise
 */
int check_if_printatble(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
