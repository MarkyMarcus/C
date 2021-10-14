#include <stdio.h>
#include <stdint.h>
#include <strings.h>

/**
 * Write a program to print the given pattern
 *
 *      0
 *     101
 *    01010
 *   1010101
 *  010101010 
 */
int
main(
    void)
{
    #define HEIGHT 5
    #define WIDTH  (HEIGHT * 2 - 1)
    #define MID (WIDTH / 2)
    uint32_t num = 0;

    for (uint32_t i = 0; i < HEIGHT; ++i)
    {
        for (uint32_t j = 0; j < WIDTH; ++j)
        {
            if (j >= MID - i && j <= MID + i)
            {
                printf("%d", num++ % 2);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
