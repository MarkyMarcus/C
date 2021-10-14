#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/**
 * Practice with conditions
 */
int
main(
    int argc __unused,
    char **argv __unused)
{
    // Create a simple condition that will always execute
    if (1)
    {
        printf("This condition is true and will execute\n");
    }

    // Create a condition that will never execute
    if (0)
    {
        printf("Since the condition is false you will never see this message\n");
    }

    // Create a if condition with an else clause
    int temp = 80;
    if (temp > 80)
    {
        printf("Wear shorts\n");
        printf("Bring water\n");
    }
    else
    {
        printf("Wear jeans\n");
        printf("Bring hot tea\n");
    }

    // TODO: Put your age in a variable and use an if/else to say if your age can drive or not
    if ()
    {
        printf("At age %d, you may drive\n", age);
    }
    else
    {
        printf("At age %d, you may not drive\n", age);
    }

    return EXIT_SUCCESS;
}
