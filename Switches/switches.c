#include <stdio.h>

/**
 * Experiment with input
 */
int
main(
    int argc,
    char **argv)
{
    // A simple switch
    int value = 0;
    switch (value)
    {
        case 0:
            printf("Value equals 0\n");
            break;
        case 1:
            printf("Value equals 1\n");
            break;
        default:
            printf("I'm not sure what value is\n");
            break;
    }

    // The cases can be in any order
    value = 2;
    switch (value)
    {
        default:
            printf("I'm not sure what value is\n");
            break;
        case 1:
            printf("Value equals 1\n");
            break;
        case 0:
            printf("Value equals 0\n");
            break;
    }

    // If break isn't used execution continue into the next case
    value = 0;
    switch (value)
    {
        case 0:
            printf("Value equals 0\n");
        case 1:
            printf("Value equals 1\n");
        default:
            printf("I'm not sure what value is\n");
    }

    // TODO: Write a switch statement to print out the first 3 arguments to main() if they exist
    switch (argc)
    {
        case 4:
            printf("Argument %d is %s\n", 3, argv[3]);
        case 3:
            printf("Argument %d is %s\n", 2, argv[2]);
        case 2:
            printf("Argument %d is %s\n", 1, argv[1]);
        case 1:
            printf("Argument %d is %s\n", 0, argv[0]);
            break;
        default:
            printf("%d is too many arguments\n", argc);
    }

    // Return success
    return 0;
}
