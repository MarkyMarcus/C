#include <stdlib.h>
#include <stdbool.h>
#include <libgen.h>
#include <stdio.h>
#include <getopt.h>

static int start = ' ';
static int end = '~';
static int count = 0;
static int key = 0;


/**
 *
 */
void
setKey(
    int new_key)
{
    count = end - start + 1;
    key = new_key % count;
}


/**
 *
 */
void
encryptString(
    char *msg)
{
    int ch;

    while (*msg != 0)
    {
        ch = *msg;
        ch = ch - start;
        ch = ch + key;
        ch = ch % count;
        ch = ch + start;
        *msg = ch;
        msg++;
    }
}


/**
 *
 */
void
decryptString(
    char *msg)
{
    int ch;

    while (*msg != 0)
    {
        ch = *msg;
        ch = ch - start;
        ch = ch - key;
        ch = ch % count;
        if (ch < 0)
        {
            ch = ch + count;
        }
        ch = ch + start;
        *msg = ch;
        msg++;
    }
}


#ifdef CAESERCIPHER_MAIN

/**
 *
 */
static void
usage(
    char *prog)
{
    fprintf(stderr, "\n");
    fprintf(stderr, "usage: %s [OPTIONS] text\n", basename(prog));
    fprintf(stderr, "OPTIONS:\n");
    fprintf(stderr, "       -d, --decrypt       # Decrypt the text\n");
    fprintf(stderr, "       -e, --encrypt       # Encrypt the text\n");
    fprintf(stderr, "       -k, --key KEY       # Use KEY for encryption/decryption, default 1\n");
    fprintf(stderr, "\n");
}


/**
 *
 */
int
main(
    int argc,
    char **argv)
{
    int result = EXIT_SUCCESS;
    int ch;
    int option_index = 0;
    bool encrypt = false;
    bool decrypt = false;
    char *progname = argv[0];
    int key = 0;

    struct option options[] = {
        {   "decrypt",  no_argument,        NULL,   'd' },
        {   "encrypt",  no_argument,        NULL,   'e' },
        {   "key",      required_argument,  NULL,   'k' },
        {   NULL,       0,                  NULL,   0   },
    };

    while ((ch = getopt_long(argc, argv, "dek:", options, &option_index)) != -1)
    {
        switch (ch)
        {
            case 'd':
                decrypt = true;
                break;
            case 'e':
                encrypt = true;
                break;
            case 'k':
                key = atoi(optarg);
                break;
            default:
                usage(progname);
                result = EXIT_FAILURE;
                goto fail;
                break;
        }
    }

    argc -= optind;
    argv += optind;

    setKey(key);

    if (argc == 0)
    {
        fprintf(stderr, "%s: A text message to encrypt/decrypt is required\n", basename(progname));
        usage(progname);
        result = EXIT_FAILURE;
        goto fail;
    }

    printf("Original message: %s\n", argv[0]);

    if (encrypt)
    {
        encryptString(argv[0]);
        printf("Encrypted message: %s\n", argv[0]);
    }

    if (decrypt)
    {
        decryptString(argv[0]);
        printf("Decrypted message: %s\n", argv[0]);
    }

fail:

    // Return result
    return result;
}

#endif
