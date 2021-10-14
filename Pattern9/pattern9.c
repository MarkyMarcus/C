#include <stdio.h>
#include <stdint.h>
#include <strings.h>

/**
 * Write a program to print the given pattern
 *
 *      a
 *     eio
 *    uaeio
 *   uaeioua
 *  eiouaeiou
 */
int
main(
    void)
{
    #define HEIGHT 5
    #define WIDTH  (HEIGHT * 2 - 1)
    #define MID (WIDTH / 2)
    uint32_t num = 0;
    char vals[] = "aeiou";

    for (uint32_t i = 0; i < HEIGHT; ++i)
    {
        for (uint32_t j = 0; j < WIDTH; ++j)
        {
            if (j >= MID - i && j <= MID + i)
            {
                printf("%c", vals[num++ % (sizeof(vals) - 1)]);
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
