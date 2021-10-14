#include <stdlib.h>
#include <stdio.h>
#include <time.h>


/**
 * Print information about a date
 */
int
main(
    int argc __unused,
    char **argv __unused)
{
    int c;
    uint32_t i = 3;

    for (i = 0; i < 3; ++i)
    //while (--i)
    //do
    {
        printf("Please enter a letter and press return: ");

        c = getchar();
        fpurge(stdin);

        switch (c)
        {
            case 'a':
                printf("You have chosen a magic letter\n");
                break;

            default:
                printf("I don't understand '%c'\n", c);
        }
    }
    //while (1);

    printf("We're finished\n");

    // Return success
    return EXIT_SUCCESS;
}
