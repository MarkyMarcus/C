#include <stdio.h>
#include <stdint.h>

/**
 * Write a program to print the given pattern
 *
 *   *       *
 *   **     **
 *   ***   ***
 *   **** ****
 *   *********
 *   **** ****
 *   ***   ***
 *   **     **
 *   *       *
 */
int
main(
    void)
{
    const uint32_t width = 9;

    for (uint32_t i = 0; i < width; ++i)
    {
        for (uint32_t j = 0; j < width; ++j)
        {
            uint32_t on = 0;
            uint32_t half = width / 2;

            if (i == half)
            {
                on = 1;
            }

            if (i < half && j <= i)
            {
                on = 1;
            }

            if (i < half && j + i >= width - 1)
            {
                on = 1;
            }

            if (i > half && j >= i)
            {
                on = 1;
            }

            if (i > half && j + i <= width - 1)
            {
                on = 1;
            }

            if (on)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Return success
    return 0;
}
