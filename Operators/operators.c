#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/**
 * Practice with operators
 */
int
main(
    int argc __unused,
    char **argv __unused)
{
    // Addition
    printf("Addition (1 + 3): %d\n", 1 + 3);

    // Subtraction
    printf("Subtration (3 - 1): %d\n", 3 - 1);

    // Multiplication
    printf("Multiplication (5 * 5): %d\n", 5 * 5);

    // Division
    printf("Division (21 / 5): %d\n", 21 / 5);

    // Division with remainder
    printf("Division with remainder (21.0 / 5): %f\n", 21.0 / 5);

    // Modulus
    printf("Modulus (21 %% 5): %d\n", 21 % 5);

    // Equal
    printf("Equal (5 == 5): %d\n", 5 == 5);
    printf("Equal (5 == 4): %d\n", 5 == 4);

    // Not Equal
    printf("Not Equal (5 != 5): %d\n", 5 != 5);
    printf("Not Equal (5 != 4): %d\n", 5 != 4);

    // Less than, Greater than
    printf("Less than (4 < 5): %d\n", 4 < 5);
    printf("Greater than (4 > 5): %d\n", 4 > 5);

    // AND
    printf("AND (1 && 1): %d\n", 1 && 1);
    printf("AND (1 && 0): %d\n", 1 && 0);
    printf("AND (0 && 0): %d\n", 0 && 0);

    // OR
    printf("OR (1 || 1): %d\n", 1 || 1);
    printf("OR (1 || 0): %d\n", 1 || 0);
    printf("OR (0 || 0): %d\n", 0 || 0);

    // NOT
    printf("NOT (!0): %d\n", !0);
    printf("NOT (!1): %d\n", !1);
    printf("NOT (!!2): %d\n", !!2);

    // TODO: Print if your age modulus 3 is greater than or equal to 1
    printf("%d\n", 35 % 3 >= 1);

    return EXIT_SUCCESS;
}
