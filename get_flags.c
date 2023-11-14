#include "main.h"

/**
 * get_flags - Calculates active flags based on the format string
 * @format: The format string.
 * @i: Pointer to the index to track the position in the format string.
 *
 * Return: The calculated flags.
 */
int get_flags(const char *format, int *i)
{
    /* - + 0 # ' ' */
    /* 1 2 4 8  16 */
    int j, curr_i;
    int flags = 0;
    const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
    const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

    // Iterate through the format string to identify flags
    for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
    {
        for (j = 0; FLAGS_CH[j] != '\0'; j++)
        {
            // Check if the current character corresponds to a flag
            if (format[curr_i] == FLAGS_CH[j])
            {
                flags |= FLAGS_ARR[j];
                break;
            }
        }

        // If the current character doesn't correspond to any flag, break the loop
        if (FLAGS_CH[j] == '\0')
        {
            break;
        }
    }

    // Update the index based on the identified flags
    *i = curr_i - 1;

    return flags;
}
