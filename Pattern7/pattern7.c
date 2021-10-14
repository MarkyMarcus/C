#include <stdio.h>
#include <stdint.h>
#include <strings.h>

/**
 * Write a program to print the given pattern
 *
 *  1
 *  2 6
 *  3 7 10
 *  4 8 11 13
 *  5 9 12 14 15
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
        for (uint32_t j = i; j < WIDTH; ++j)
        {
            vals[j][i] = num++;
        }
    }

    for (uint32_t i = 0; i < WIDTH; ++i)
    {
        for (uint32_t j = 0; j < WIDTH; ++j)
        {
            vals[i][j] == 0 ? printf("   "): printf("%3d", vals[i][j]);
        }
        printf("\n");
    }

    return 0;
}
