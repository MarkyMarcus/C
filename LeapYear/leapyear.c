#include <stdlib.h>
#include <stdio.h>

#define FALSE 0
#define TRUE  1

/**
 * Determine if a year is a leap year or not
 *
 * @param year  Year to test
 *
 * @retval TRUE     year is a leap year
 * @retval FALSE    year is not a leap year
 *
 * if (year is not divisible by 4) then (it is a common year)
 * else if (year is not divisible by 100) then (it is a leap year)
 * else if (year is not divisible by 400) then (it is a common year)
 * else (it is a leap year)
 */
static int
isLeapYear(
    int year)
{
    /*
    if (year % 4 != 0)
    {
        return FALSE;
    }
    else if (year % 100 != 0)
    {
        return TRUE;
    }
    else if (year % 400 != 0)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
    */

    if (year % 400 == 0)
    {
        return TRUE;
    }
    if (year % 100 == 0)
    {
        return FALSE;
    }
    return year % 4 == 0;
}


int
main(
    int argc,
    char **argv)
{
    int year = 0;

    // Validate that we have the correct number of arguments
    if (argc != 2)
    {
        fprintf(stderr, "ERROR: Usage: leapyear YEAR\n");
        return EXIT_FAILURE;
    }

    year = atoi(argv[1]); 
    printf("You entered: %i\n", year);

    if (year < 1)
    {
        fprintf(stderr, "ERROR: Year %i is not a valid year\n", year);
        return EXIT_FAILURE;
    }

    if (isLeapYear(year))
    {
        printf("Year %i is a leap year\n", year);
    }
    else
    {
        printf("Year %i is NOT a leap year\n", year);
    }

    // Return result
    return EXIT_SUCCESS;
}
