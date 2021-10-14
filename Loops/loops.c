#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/**
 * Practice with loops
 */
int
main(
    int argc __unused,
    char **argv __unused)
{
    int count = 0;

    // Create a for-loop
    for (count = 1; count <= 5; count++)
    {
        printf("for-loop count is %d\n", count);
    }

    // Create a while-loop
    count = 1;
    while (count <= 5)
    {
        printf("while-loop count is %d\n", count);
        count = count + 1;
    }

    // Create a do-while-loop
    count = 1;
    do
    {
        printf("do-while-loop count is %d\n", count++);
    }
    while (count <= 5);

    // TODO: Create a loop that counts from 1 to 100 skipping by 5

    return EXIT_SUCCESS;
}
