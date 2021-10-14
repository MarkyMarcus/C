#include <stdio.h>

/**
 * Experiment with format specifiers
 */
int
main(
    int argc __unused,
    char **argv __unused)
{
    // Print with the integer format specifier
    printf("This is an integer: %d\n", 1234);

    // Print using the string format specifier
    printf("The secret word is %s\n", "abracadabra");

    // Multiple format specifiers can be used in one output statement
    printf("%s is %d inches or %f feet\n", "Sam", 66, 5.5);

    // Expressions can be used as values
    printf("There are %d seconds in a year\n", 365 * 24 * 60 * 60);

    // TODO: Print your name and your age in one statement using format specifiers
    printf("%s is %d years old\n", "Eric", 25);

    // Return success
    return 0;
}
