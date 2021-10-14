#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>


/**
 * Print the current version of SQLite
 */
int
main(
    int argc __unused,
    char **argv __unused)
{
    // Call an external function
    printf("The current version of SQLite is %s\n", sqlite3_libversion());

    // Return success
    return EXIT_SUCCESS;
}
