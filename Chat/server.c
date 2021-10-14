#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <libgen.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS (100)
#define NO_CLIENT   (-1)

int clients[MAX_CLIENTS];

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
    fprintf(stderr, "       -i, --ip IP_ADDRESS         # Server IP address\n");
    fprintf(stderr, "       -p, --port PORT             # Server port\n");
    fprintf(stderr, "\n");
}


/**
 *
 */
static int
addClient(
    int sock)
{
    for (uint32_t i = 0; i < MAX_CLIENTS; ++i)
    {
        if (clients[i] == NO_CLIENT)
        {
            clients[i] = sock;
            break;
        }
    }

    return 0;
}


/**
 *
 */
static int
removeClient(
    int sock)
{
    for (uint32_t i = 0; i < MAX_CLIENTS; ++i)
    {
        if (clients[i] == sock)
        {
            close(clients[i]);
            clients[i] = NO_CLIENT;
            break;
        }
    }

    return 0;
}


/**
 *
 */
static int
broadcast(
    uint8_t *msg,
    int sock)
{
    for (uint32_t i = 0; i < MAX_CLIENTS; ++i)
    {
        if (clients[i] != NO_CLIENT && clients[i] != sock)
        {
            int rc = sendto(clients[i], msg, strlen((char *) msg), 0, NULL, 0);
        }
    }

    return 0;
}


/**
 *
 */
static void *
clientthread(
    void *arg)
{
    uint8_t msg[2048];
    ssize_t msgsz;
    int sock = (int) arg;
    struct sockaddr_in client;
    char ip[INET_ADDRSTRLEN];
    uint16_t port;
    size_t sock_len = sizeof(client);

    getpeername(sock, (struct sockaddr *) &client, (socklen_t *) &sock_len);

    inet_ntop(AF_INET, &client.sin_addr.s_addr, ip, INET_ADDRSTRLEN);
    port = ntohs(client.sin_port);

    while (1)
    {
        msgsz = recvfrom(sock, msg, sizeof(msg), 0, NULL, NULL);

        if (msgsz == 0)
        {
            printf("%s:%hu disconnected\n", ip, port);
            removeClient(sock);
            break;
        }
        else
        {
            printf("%s:%hu -> %s\n", ip, port, msg);
            broadcast(msg, sock);
            bzero(msg, sizeof(msg));
        }
    }
    
    return NULL;
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
    char *ip = "127.0.0.1";
    char *port = "8000";
    int sock = -1;
    intptr_t client_sock = -1;
    struct sockaddr_in server;
    struct sockaddr_in client;
    int rc;
    size_t sock_len = sizeof(client);
    char ipaddr[INET_ADDRSTRLEN];

    struct option options[] = {
        {   "ip",           required_argument,  NULL,   'i' },
        {   "port",         required_argument,  NULL,   'p' },
        {   NULL,           0,                  NULL,   0   },
    };

    while ((ch = getopt_long(argc, argv, "i:p:", options, &option_index)) != -1)
    {
        switch (ch)
        {
            case 'i':
                ip = optarg;
                break;
            case 'p':
                port = optarg;
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

    // Initialize client array
    for (uint32_t i = 0; i < MAX_CLIENTS; ++i)
    {
        clients[i] = NO_CLIENT;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        fprintf(stderr, "Failed to create socket\n");
        goto fail;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(port));
    inet_pton(AF_INET, ip, &server.sin_addr.s_addr);

    rc = bind(sock, (struct sockaddr *) &server, sizeof(server));
    if (rc)
    {
        fprintf(stderr, "Failed to bind socket\n");
        goto fail;
    }

    rc = listen(sock, MAX_CLIENTS);
    if (rc)
    {
        fprintf(stderr, "Failed to bind socket\n");
        goto fail;
    }

    inet_ntop(AF_INET, &server.sin_addr.s_addr, ipaddr, INET_ADDRSTRLEN);
    printf("Listening on %s:%hu\n", ipaddr, ntohs(server.sin_port));
    
    while ((client_sock = accept(sock, (struct sockaddr *) &client, (socklen_t *) &sock_len)))
    {
        pthread_t thread;

        addClient(client_sock);

        inet_ntop(AF_INET, &client.sin_addr.s_addr, ipaddr, INET_ADDRSTRLEN);

        printf("%s:%hu connected\n", ipaddr, ntohs(client.sin_port));

        pthread_create(&thread, NULL, clientthread, (void *) client_sock);
    }

fail:

    for (uint32_t i = 0; i < MAX_CLIENTS; ++i)
    {
        if (clients[i] != NO_CLIENT)
        {
            close(clients[i]);
        }
    }

    if (sock != -1)
    {
        close(sock);
    }

    return result;
}
