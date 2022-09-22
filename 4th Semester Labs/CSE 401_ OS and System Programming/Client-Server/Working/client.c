#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <sys/time.h>
#include <string.h>
#include <pthread.h>

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

int main(int argc, char **argv)
{

    int sockfd, n, SERVER_PORT;
    int sendbytes;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE];
    char recvline[MAXLINE];
    char *username;
    pthread_t thread_id;


    // check for ip address
    if (argc != 4)
    {
        printf("usage: ./c <server address> <port>");
        exit(0);
    }

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error while creating the socket!");
    }

    // set server address
    bzero(&servaddr, sizeof(servaddr));
    SERVER_PORT = atoi(argv[2]);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT); /* chat server */

    // convert ip address to binary
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
    {
        printf("inet_pton error for %s ", argv[1]);
    }

    // connect to server
    if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("Connection Failed!");
    }

    client.sockfd = sockfd;
    client.ip = (argv[1]);
    client.port = SERVER_PORT;
    client.username = argv[3];

    // pass user name to server    
    write(sockfd, argv[3], strlen(argv[3]));

    // always running listen mode
    if (pthread_create(&thread_id, NULL, readServer, (void *)&client) < 0)
    {
        perror("could not create thread");
        return 1;
    };

    while (1)
    {
        // printf("C-Write\n");
        bzero(sendline, MAXLINE);
        scanf("%[^\n]%*c", sendline);

        // write to server
        write(sockfd, (char *)sendline, strlen((char *)sendline));
    }

}

void *readServer(void *socket_struct)
{

    char sendline[MAXLINE + 1];
    char recvline[MAXLINE + 1];
    int n;

    struct client_info *client = (struct client_info *)socket_struct;
    int fd = client->sockfd;
    char * ip = client->ip;
    int port = client->port;
    char *name = client->username;

    // always listen to server
    while (1)
    {
        // get from server
        // printf("C-Read\n");
        bzero(recvline, MAXLINE);
        n = read(fd, recvline, MAXLINE - 1);
        printf("%s", recvline);

        if (!strcmp(recvline, "exit") || !strcmp(recvline, "exit\r\n"))
        {
            sprintf(sendline, "%s has left the chat", name);
            write(fd, (char *)sendline, strlen((char *)sendline));

            // printf("\n[%s disconnected...]\n", name);
            exit(0);    // exit 
        }
        
    }

}