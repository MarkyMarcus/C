#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/**
 * Same function
 */
void
foo(
    void)
{
    printf("I am function foo\n");
}


// Declare a function name bar that takes no parameters and returns an int
int bar(int);

void
my_func(
    char *string)
{
    printf("%s\n", string);
}


/**
 * Practice with functions
 */
int
main(
    int argc __unused,
    char **argv __unused)
{
    /*
     * A function declaration has the return type, name, parameter types.
     * A function definition has the code for the function.
     * Function must be declared before they can be referenced.
     * We can declare and define a function at the same time.
     */

    /*
     * foo() has be defined above which also declares it.  It takes zero parameters
     * and doesn't return a value
     */
    foo();

    /*
     * bar() is defined below so it must be declared above.  This requires writing the
     * beginning part of the function twice so it's used less often.
     */
    int value;
    value = bar(2);
    printf("bar() returned %d\n", value);

    // TODO: Write a function that takes a string as a parameter and prints it out
    my_func("Hello");

    return EXIT_SUCCESS;
}

int
bar(
    int a)
{
    printf("I am function bar and I return an int\n");
    return a * 2;
}
