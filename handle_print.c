#include "main.h"

/**
 * handle_print - Prints an argument based on its type and
 * displays it on the stdout
 * @fmt: Formatted string containing the format specifiers.
 * @ind: Index to keep track of the current position in fmt.
 * @list: List of arguments to be printed.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting.
 * @width: Width specification.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * Return: The number of characters printed, or -1 on error.
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
                 int flags, int width, int precision, int size)
{
    int i, unknown_len = 0, printed_chars = -1;

    // Array of format specifiers and corresponding functions
    fmt_t fmt_types[] = {
        {'c', print_char}, {'s', print_string}, {'%', print_percent},
        {'i', print_int}, {'d', print_int}, {'b', print_binary},
        {'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
        {'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
        {'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
    };

    // Loop through the format specifiers and find a match
    for (i = 0; fmt_types[i].fmt != '\0'; i++)
    {
        if (fmt[*ind] == fmt_types[i].fmt)
        {
            // Call the corresponding print function and return its result
            return fmt_types[i].fn(list, buffer, flags, width, precision, size);
        }
    }

    // If no match is found
    if (fmt_types[i].fmt == '\0')
    {
        if (fmt[*ind] == '\0')
        {
            // End of format string, return -1 as an error
            return -1;
        }

        // Handle the case where the specifier is '%%'
        unknown_len += write(1, "%%", 1);

        if (fmt[*ind - 1] == ' ')
        {
            // If there was a space before '%%', add a space
            unknown_len += write(1, " ", 1);
        }
        else if (width)
        {
            // Handle width specification by adjusting the index
            --(*ind);
            while (fmt[*ind] != ' ' && fmt[*ind] != '%')
                --(*ind);

            if (fmt[*ind] == ' ')
                --(*ind);

            // Return 1 to indicate one character was printed
            return 1;
        }

        // Write the character directly to stdout
        unknown_len += write(1, &fmt[*ind], 1);
        return unknown_len;
    }

    // Return the total number of printed characters
    return printed_chars;
}
