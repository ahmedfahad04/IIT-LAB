#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <sys/time.h>
#include <string.h>
#include <pthread.h>

#define SERVER_PORT 8080
#define MAXLINE 4096
#define SA struct sockaddr

struct client_info
{
    char *ip;
    int sockfd;
    int port;
    char *username;

} client;

void *readServer(void *);
int errmsg(int rval, char *msg);

pthread_mutex_t cmutex;

int main(int argc, char **argv)
{

    int sockfd, n;
    int sendbytes;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE];
    char recvline[MAXLINE];
    char *username;
    pthread_t thread_id;

    pthread_mutex_init(&cmutex, NULL);

    // check for ip address
    if (argc != 3)
    {
        printf("usage: ./c <server address> <username>\n");
        exit(0);
    }

    // create socket
    errmsg((sockfd = socket(AF_INET, SOCK_STREAM, 0)), "Error while creating the socket!");

    // set server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT); /* chat server */

    // convert ip address to binary
    errmsg(inet_pton(AF_INET, argv[1], &servaddr.sin_addr), "inet_pton error");

    // connect to server
    errmsg(connect(sockfd, (SA *)&servaddr, sizeof(servaddr)), "Connection Failed!!!");
    printf("Connection Established ------- \n");

    // set client info
    client.sockfd = sockfd;
    client.ip = (argv[1]);
    client.port = SERVER_PORT;
    client.username = argv[2];

    // pass user name to server
    write(sockfd, argv[2], strlen(argv[2]));

    // always running in listen/reading mode
    errmsg(pthread_create(&thread_id, NULL, readServer, (void *)&client), "Failed to create thread");

    // concurrently send messages to server
    while (1)
    {
        // printf("C-Write\n");
        bzero(sendline, MAXLINE);
        // scanf("%[^\n]%*c", sendline);
        fgets(sendline, MAXLINE, stdin);

        // pthread_mutex_lock(&cmutex);
        // write to server
        write(sockfd, (char *)sendline, strlen((char *)sendline));
        // pthread_mutex_unlock(&cmutex);
    }
}

int errmsg(int rval, char *msg)
{
    if (rval < 0)
    {
        perror(msg);
        exit(1);
    }
    return rval;
}

void *readServer(void *socket_struct)
{

    char sendline[MAXLINE + 1];
    char recvline[MAXLINE + 1];
    int n;

    struct client_info *client = (struct client_info *)socket_struct;
    int fd = client->sockfd;
    char *ip = client->ip;
    int port = client->port;
    char *name = client->username;

    // always listen to server
    while (1)
    {
        pthread_mutex_lock(&cmutex);

        // read from server
        // printf("C-Read\n");
        bzero(recvline, MAXLINE);
        n = read(fd, recvline, MAXLINE);

        if (!strcmp(recvline, "exit") || !strcmp(recvline, "exit\r\n"))
        {
            sprintf(sendline, "%s has left the chat...\n", name);
            write(fd, (char *)sendline, strlen((char *)sendline));

            exit(0); // exit
        }

        printf("%s", recvline);


        pthread_mutex_unlock(&cmutex);
    }
}
