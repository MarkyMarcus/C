#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define GET_MIN(x) \
    ((x)(1ULL << ((sizeof(x) << 3) - 1)))

#define GET_MAX(x) \
    (~(GET_MIN(x)))

#define GET_UNSIGNED_MAX(x) \
    ((x)(~0))

/**
 * Print information out about varies data types
 */
int
main(
    int argc __unused,
    char **argv __unused)
{
    printf("\n");
    printf("\t%-24s%-24s%-24s%-24s\n",      "Type",             "Bytes",                    "Min",                  "Max");
    printf("\t%-24s%-24zu%-24d%-24d\n",     "char",             sizeof(char),               GET_MIN(char),          GET_MAX(char));
    printf("\t%-24s%-24zu%-24d%-24d\n",     "short",            sizeof(short),              GET_MIN(short),         GET_MAX(short));
    printf("\t%-24s%-24zu%-24d%-24d\n",     "int",              sizeof(int),                GET_MIN(int),           GET_MAX(int));
    printf("\t%-24s%-24zu%-24ld%-24ld\n",   "long",             sizeof(long),               GET_MIN(long),          GET_MAX(long));
    printf("\t%-24s%-24zu%-24e%-24e\n",     "float",            sizeof(float),              -1.2E-38,               3.4E+38);
    printf("\t%-24s%-24zu%-24le%-24le\n",   "double",           sizeof(double),             -2.3E-308,              1.7E+308);
    printf("\t%-24s%-24zu%-24u%-24u\n",     "unsigned char",    sizeof(unsigned char),      0,                      GET_UNSIGNED_MAX(unsigned char));
    printf("\t%-24s%-24zu%-24u%-24u\n",     "unsigned short",   sizeof(unsigned short),     0,                      GET_UNSIGNED_MAX(unsigned short));
    printf("\t%-24s%-24zu%-24u%-24u\n",     "unsigned int",     sizeof(unsigned int),       0,                      GET_UNSIGNED_MAX(unsigned int));
    printf("\t%-24s%-24zu%-24u%-24lu\n",    "unsigned long",    sizeof(unsigned long),      0,                      GET_UNSIGNED_MAX(unsigned long));
    printf("\n");

    return EXIT_SUCCESS;
}
