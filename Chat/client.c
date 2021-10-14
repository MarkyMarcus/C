#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <libgen.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "caesarcipher.h"

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
    fprintf(stderr, "       -e, --encryption CIPHER     # Encryption algorithm to use\n");
    fprintf(stderr, "       -i, --ip IP_ADDRESS         # Server IP address\n");
    fprintf(stderr, "       -k, --key KEY               # Key to use for encryption\n");
    fprintf(stderr, "       -p, --port PORT             # Server port\n");
    fprintf(stderr, "       -u, --username USERNAME     # Username to use in chatroom\n");
    fprintf(stderr, "\n");
}


/**
 *
 */
static void
rstrip(
    char *str)
{
    for (int i = strlen(str) - 1; i >= 0; --i)
    {
        if (isspace(str[i]))
        {
            str[i] = 0;
        }
        else
        {
            break;
        }
    }
}


/**
 *
 */
static int
client(
    char *ip,
    char *port,
    char *username)
{
    int result = EXIT_SUCCESS;
    struct sockaddr_in server;
    int sock = -1;
    fd_set read_fds;
    int rc;
    char msg[2048];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sock)
    {
        fprintf(stderr, "Failed to create socket\n");
        goto fail;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(port));
    inet_pton(AF_INET, ip, &server.sin_addr.s_addr);

    rc = connect(sock, (struct sockaddr *) &server, sizeof(server));
    if (rc)
    {
        fprintf(stderr, "Failed to create socket\n");
        goto fail;
    }

    FD_ZERO(&read_fds);

    while (1)
    {
        FD_SET(STDIN_FILENO, &read_fds);
        FD_SET(sock, &read_fds);

        switch(select(sock + 1, &read_fds, NULL, NULL, NULL))
        {
            case -1:
                printf("select() error\n");
                result = EXIT_FAILURE;
                goto fail;
            default:
                if (FD_ISSET(STDIN_FILENO, &read_fds))
                {
                    bzero(msg, sizeof(msg));
                    sprintf(msg, "%s> ", username);
                    read(STDIN_FILENO, msg + strlen(msg), sizeof(msg) - strlen(msg));
                    rstrip(msg);
                    encryptString(msg);
                    sendto(sock, msg, strlen(msg), 0, NULL, 0);
                }

                if (FD_ISSET(sock, &read_fds))
                {
                    bzero(msg, sizeof(msg));
                    if (read(sock, msg, sizeof(msg)) == 0)
                    {
                        printf("Server disconnected\n");
                        goto fail;
                    }
                    decryptString(msg);
                    printf("%s\n", msg);
                }
        }
    }

fail:

    if (-1 != sock)
    {
        close(sock);
    }

    return result;
}


/**
 * Print information about a date
 */
int
main(
    int argc,
    char **argv)
{
    int result = EXIT_SUCCESS;
    int ch;
    int option_index = 0;
    char *progname = argv[0];
    char *encryption = "plaintext";
    char *ip = "127.0.0.1";
    char *key = "0";
    char *port = "8000";
    char *username = "Anonymous";

    struct option options[] = {
        {   "encryption",   required_argument,  NULL,   'e' },
        {   "ip",           required_argument,  NULL,   'i' },
        {   "key",          required_argument,  NULL,   'k' },
        {   "port",         required_argument,  NULL,   'p' },
        {   "username",     required_argument,  NULL,   'u' },
        {   NULL,           0,                  NULL,   0   },
    };

    while ((ch = getopt_long(argc, argv, "e:i:k:p:u:", options, &option_index)) != -1)
    {
        switch (ch)
        {
            case 'e':
                encryption = optarg;
                break;
            case 'i':
                ip = optarg;
                break;
            case 'k':
                key = optarg;
                break;
            case 'p':
                port = optarg;
                break;
            case 'u':
                username = optarg;
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

    setKey(atoi(key));

    client(ip, port, username);

fail:

    return result;
}
