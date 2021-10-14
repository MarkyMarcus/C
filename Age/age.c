#include <stdlib.h>
#include <stdio.h>
#include <time.h>


/**
 *
 */
void
interestingFacts(
    time_t seconds)
{
    time_t minutes = 0;
    time_t hours = 0;
    time_t days = 0;
    time_t weeks = 0;
    time_t years = 0;

    // TODO: Calcuate minutes
    minutes = 
    // TODO: Calcuate hours
    hours = 
    // TODO: Calcuate days
    days = 
    // TODO: Calcuate weeks
    weeks = 
    // TODO: Calcuate years
    years = 

    printf("Seconds: %lu\n", seconds);
    printf("Minutes: %lu\n", minutes);
    printf("Hours: %lu\n", hours);
    printf("Days: %lu\n", days);
    printf("Weeks: %lu\n", weeks);
    printf("Years: %lu\n", years);

    // Tell the user if they can drive (16+)
    if (years >= 16)
    {
        // TODO: Print a message to the user
    }
    else
    {
        // TODO: Print a message to the user
    }

    // TODO: Tell the user if they can vote (18+)
    if 
    {
        printf("You may vote\n");
    }
    else
    {
        printf("You may not vote\n");
    }

    // TODO: Tell the user if they can be predient (35+)
    if 
    {
        printf("You may be president\n");
    }
    else
    {
        printf("You may not be president\n");
    }
}


/**
 * Print information about a date
 */
int
main(
    int argc __unused,
    char **argv __unused)
{
    time_t now_seconds = 0;
    struct tm birthday = {0};
    time_t age_in_seconds = 0;

    // Get the current time in seconds since January 1, 1970 (known as epoch)
    now_seconds = time(NULL);

    // Set the birthday to a specific day
    birthday.tm_year = 2018 - 1900;
    birthday.tm_mon = 11;
    birthday.tm_mday = 29;

    // Print the dates
    printf("The birthday is %s", asctime(&birthday));
    printf("Today's date is %s", asctime(localtime(&now_seconds)));

    // Calculate the seconds
    age_in_seconds = now_seconds - mktime(&birthday);

    // Call our function to print out interesting facts
    interestingFacts(age_in_seconds);

    // Return success
    return EXIT_SUCCESS;
}
