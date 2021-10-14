#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/**
 * Practice with variables
 */
int
main(
    int argc __unused,
    char **argv __unused)
{
    // Create a variable to hold a signed integer
    int foo = 5;

    // Use the variable to print the value
    printf("The value of foo is %d\n", foo);

    // A variable can store an expression result
    int bar = 5 * 5 * 4;

    // A variable can be copied into another variable
    int combo = foo;
    printf("The value of combo is %d\n", combo);

    // TODO: Save the year in a variable and print it out as a integer and hexadecimal
    int year = 2019;
    printf("Year %d is %x in hexadecimal\n", year, year);

    return EXIT_SUCCESS;
}
