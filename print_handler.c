#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @frmat: Formatted string in which to print the arguments.
 * @list: argument list
 * @ind: ind
 * @buffer: array to handle print.
 * @flags: active flag
 * @width: get width.
 * @precision: specifier
 * @size: specifier
 * Return: 1 or 2
 */
int handle_print(const char *frmat, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	frmatn frmatnypes[] = {
		{'c', print_char}, {'s', str_print}, {'%', percent_print},
		{'i', print_int}, {'d', print_int}, {'b', bin_print},
		{'u', unsign_print}, {'o', oct_print}, {'x', hexa_dec_print},
		{'X', hexa_upper_print}, {'p', print_ptr}, {'S', non_printable_char_print},
		{'r', reverse_str}, {'R', rot13_str}, {'\0', NULL}
	};
	for (i = 0; frmatnypes[i].frmat != '\0'; i++)
		if (frmat[*ind] == frmatnypes[i].frmat)
			return (frmatnypes[i].fn(list, buffer, flags, width, precision, size));

	if (frmatnypes[i].frmat == '\0')
	{
		if (frmat[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (frmat[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (frmat[*ind] != ' ' && frmat[*ind] != '%')
				--(*ind);
			if (frmat[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &frmat[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
