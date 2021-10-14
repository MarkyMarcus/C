#include <stdio.h>
#include <stdint.h>

/**
 * Write a program to print this patter
 *
 *  1
 *  01
 *  101
 *  0101
 *  10101
 */
int
main(
    void)
{
    const int32_t len = 5;
    uint32_t val = 1;

    for (uint32_t i = 0; i < len; ++i)
    {
        for (uint32_t j = 0; j <= i; ++j)
        {
            printf("%d", val);
            val = (val == 0) ? 1 : 0;
        }
        printf("\n");
    }

    // Return success
    return 0;
}
