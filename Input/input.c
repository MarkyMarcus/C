#include <stdio.h>

/**
 * Experiment with input
 */
int
main(
    int argc,
    char **argv)
{
    // Print the number of arguments passed to this program.  The first is the executable itself
    printf("The number arguments is %d\n", argc);

    // Print the first argument which is the name of the executable
    printf("The first argument is %s\n", argv[0]);

    // If a paramters was given it will start at argv[1].  Otherwise this is crash our program
    printf("The second argument is %s\n", argv[1]);

    // We can ask for more input, such as an integer
    int number;

    printf("Please enter a number: ");
    scanf("%d", &number); // We must pass the address of where we want the value stored

    printf("You entered number %d\n", number);

    // We can also ask for a string
    char name[256];  // A name up to 255 characters.  The 256th is for the \0

    printf("Please enter your name: ");
    scanf("%s", name); // Same as &name[0]

    printf("Your name is %s\n", name);

    // TODO: Ask the user for their age and favorite color then print it out
    int age;
    char color[256];

    printf("Please enter your age: ");
    scanf("%d", &age);

    printf("Please enter your favorite color: ");
    scanf("%s", color);

    printf("Your age is %d and your favorite color is %s\n", age, color);

    // Return success
    return 0;
}
