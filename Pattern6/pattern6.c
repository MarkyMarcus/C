#include <stdio.h>
#include <stdint.h>
#include <strings.h>

/**
 * Write a program to print the given pattern
 *
 *  4321234
 *  432 234
 *  43   34
 *  4     4
 */
int
main(
    void)
{
    #define MIN 1
    #define MAX 4
    #define COUNT ((MAX) - (MIN) + 1)

    for (uint32_t i = 1; i <= COUNT; ++i)
    {
        uint32_t n;
        for (int32_t j = MAX * -1; j <= MAX; ++j)
        {
            if (j == 0 || j == MIN)
            {
                continue;
            }

            n = (j < 0) ? j * -1 : j;

            if (n < i)
            {
                printf(" ");
            }
            else
            {
                printf("%d", n);
            }
            
        }
        printf("\n");
    }

    return 0;
}
