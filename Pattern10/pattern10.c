#include <stdio.h>
#include <stdint.h>
#include <strings.h>

/**
 * Write a program to print the given pattern
 *
 *      1
 *     234
 *    56789
 *   8765432
 *  123456789
 */
int
main(
    void)
{
    #define HEIGHT 5
    #define WIDTH  (HEIGHT * 2 - 1)
    #define MID (WIDTH / 2)
    #define POSITIVE 0
    #define NEGATIVE 1
    uint32_t num = 1;
    uint32_t dir = 0;

    for (uint32_t i = 0; i < HEIGHT; ++i)
    {
        for (uint32_t j = 0; j < WIDTH; ++j)
        {
            if (j >= MID - i && j <= MID + i)
            {
                printf("%d", num);
                num += dir == POSITIVE ? 1 : -1;
                if (num == 9) dir = NEGATIVE;
                if (num == 1) dir = POSITIVE;
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
