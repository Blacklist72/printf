#include "main.h"

/**
 * get_precision - Calculates the precision for printing based on the format string
 * @format: The format string.
 * @i: Pointer to the index to track the position in the format string.
 * @list: The list of arguments.
 *
 * Return: The calculated precision or -1 if none is specified.
 */
int get_precision(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int precision = -1;

    /* Check if precision is specified with a dot '.' */
    if (format[curr_i] != '.')
    {
        return precision;
    }

    precision = 0;

    /* Process the precision specifier */
    for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
    {
        if (is_digit(format[curr_i]))
        {
            precision *= 10;
            precision += format[curr_i] - '0';
        }
        else if (format[curr_i] == '*')
        {
            curr_i++;
            precision = va_arg(list, int);
            break;
        }
        else
        {
            break;
        }
    }

    /* Update the index based on the precision specifier */
    *i = curr_i - 1;

    return precision;
}
