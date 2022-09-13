#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <sys/time.h>
#include <string.h>

#define MAXLINE 4096
#define SA struct sockaddr

int serverActivity(int fd, char ip[], int port);

int main(int argc, char **argv)
{

    int sockfd, n, SERVER_PORT;
    int sendbytes;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE];
    char recvline[MAXLINE];

    // check for ip address
    if (argc != 3)
    {
        printf("usage: ./c <server address> <port>");
    }

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error while creating the socket!");
    }

    SERVER_PORT = atoi(argv[2]);

    // set server address
    bzero(&servaddr, sizeof(servaddr));
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

    while (1)
    {
        int flag = serverActivity(sockfd, argv[1], SERVER_PORT);
        if (flag == 0)
            break;
    }
}

int serverActivity(int fd, char ip[], int port)
{

    char buff[MAXLINE + 1];
    char recvline[MAXLINE + 1];
    int n;

    // write to server
    printf("\nEnter the string: ");
    fgets(buff, MAXLINE, stdin);
    write(fd, (char *)buff, strlen((char *)buff));

    // read from server
    memset(recvline, 0, MAXLINE);
    while ((n = read(fd, recvline, MAXLINE - 1)) > 0)
    {
        fprintf(stdout, "\nServer: %s", recvline);

        if (recvline[n - 1] == '\n')
        {
            break;
        }

        memset(recvline, 0, MAXLINE);
    }

    // if n is negative then error
    if (n < 0)
    {
        printf("Read error");
    }

    if (!strcmp(recvline, "exit\n") || !strcmp(recvline, "exit\r\n"))
    {
        // printf("\n[Client %s:%d disconnected]\n", ip, port);
        return 0;
    }
}