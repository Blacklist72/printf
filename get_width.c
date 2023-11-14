#include "main.h"

/**
 * get_width - Calculates the width for printing and returns the result
 * @format: The format string.
 * @i: Pointer to the index to track the position in the format string.
 * @list: The list of arguments.
 *
 * Return: The calculated width.
 */
int get_width(const char *format, int *i, va_list list)
{
    int curr_i;
    int width = 0;

    for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
    {
        if (is_digit(format[curr_i]))
        {
            // Update the width based on the digits in the format string
            width *= 10;
            width += format[curr_i] - '0';
        }
        else if (format[curr_i] == '*')
        {
            // Handle the case where width is specified as an argument
            curr_i++;
            width = va_arg(list, int);
            break;
        }
        else
        {
            // Exit the loop if a non-digit or '*' is encountered
            break;
        }
    }

    // Update the index and return the calculated width
    *i = curr_i - 1;
    return width;
}
