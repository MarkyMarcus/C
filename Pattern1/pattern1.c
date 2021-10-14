#include <stdio.h>
#include <stdint.h>

/**
 * Write a program to print the given pattern
 *
 *  975313579
 *   9753579
 *    97579
 *     979
 *      9
 */
int
main(
    void)
{
    const int32_t val = 9;
    const int32_t inc = 2;

    for (int32_t i = 0; i < (val / inc) + 1; ++i)
    {
        for (int32_t j = val * -1 - i * inc; j <= val; j += inc)
        {
            if ((j < 0 && j < val * -1) || (j > 0 && j > val))
            {
                printf(" ");
            }
            else
            {
                printf("%d", (j < 0) ? j * -1 : j);
            }

            if (j < 0 && j + inc * (i + 1) > 0)
            {
                j *= -1;
            }
        }
        printf("\n");
    }

    // Return success
    return 0;
}
