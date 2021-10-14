#include <stdio.h>
#include <stdint.h>
#include <strings.h>

/**
 * Write a program to print the given pattern
 *
 *             1
 *           3 2
 *         6 5 4
 *      10 9 8 7
 *    1514131211
 */
int
main(
    void)
{
    #define WIDTH 5
    uint32_t vals[WIDTH][WIDTH];
    uint32_t num = 1;

    bzero(&vals, sizeof(vals));

    for (uint32_t i = 0; i < WIDTH; ++i)
    {
        for (uint32_t j = 0; j <= i; ++j)
        {
            vals[i][WIDTH - 1 - j] = num++;
        }
    }

    for (uint32_t i = 0; i < WIDTH; ++i)
    {
        for (uint32_t j = 0; j < WIDTH; ++j)
        {
            vals[i][j] == 0 ? printf("  "): printf("%2d", vals[i][j]);
        }
        printf("\n");
    }

    return 0;
}
