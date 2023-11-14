#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buffr_ind = 0;
	va_list list;
	char buffer[BUFFR_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffr_ind++] = format[i];
			if (buffr_ind == BUFFR_SIZE)
				print_buffer(buffer, &buffr_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buffr_ind);
			flags = specifier_flags(format, &i);
			width = specifier_width(format, &i, list);
			precision = specifier_precision(format, &i, list);
			size = specifier_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buffr_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buffr_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buffr_ind)
{
	if (*buffr_ind > 0)
		write(1, &buffer[0], *buffr_ind);

	*buffr_ind = 0;
}
