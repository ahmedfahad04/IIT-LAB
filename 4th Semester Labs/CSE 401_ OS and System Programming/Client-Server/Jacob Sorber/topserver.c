#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <sys/time.h>
#include <string.h>

#define MAXLINE 4096
#define BACKLOG 10
#define SA struct sockaddr

int serverActivity(int fd, char respns[], char ip[], int port);
int total_connection = 0;

int main(int argc, char **argv)
{

    int listenfd, connfd, n, SERVER_PORT, enable = 1;
    struct sockaddr_in servaddr;
    struct sockaddr_in their_addr;

    if (argc != 2)
    {
        printf("usage: ./s <SERVER_PORT>\n");
        return 0;
    }

    // create socket
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error while creating the socket!");
    }

    SERVER_PORT = atoi(argv[1]);
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));

    // set server address
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERVER_PORT); /* chat server */

    // bind socket to server address
    if (bind(listenfd, (SA *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("Binding Error");
    }

    // listen for connections
    if ((listen(listenfd, BACKLOG)) < 0)
    {
        printf("Listen Error");
    }

    printf("Server is listening on port %d\n", SERVER_PORT);

    while (1)
    {
        struct sockaddr_in addr;
        socklen_t addr_len;
        char client_addr[MAXLINE + 1];
        char response[MAXLINE] = {0};
        char exitcode[MAXLINE] = {0};
        int client_port;
        pid_t pid;

        // accept connection
        connfd = accept(listenfd, (SA *)&addr, &addr_len);
        total_connection++;

        inet_ntop(AF_INET, &(addr.sin_addr), client_addr, MAXLINE);
        printf("\n===========>[Client %d - %s:%d connected]<===========\n", total_connection, client_addr, addr.sin_port);

        if ((pid = fork()) == 0)
        {
            close(listenfd);
            while (1)
            {
                int flag = serverActivity(connfd, response, client_addr, addr.sin_port);

                if (flag == 0)
                    break;
            }
            close(connfd);
            exit(0);
        }

        // parent process
        else
        {
            close(connfd);
        }
    }
}

int serverActivity(int fd, char respns[], char ip[], int port)
{

    char buff[MAXLINE + 1];
    char recvline[MAXLINE + 1];
    int n;

    memset(recvline, 0, MAXLINE);

    // read message from client
    while ((n = read(fd, recvline, MAXLINE - 1)) > 0)
    {
        fprintf(stdout, "\n[%s:%d] => %s", ip, port, recvline);

        if (recvline[n - 1] == '\n')
        {
            break;
        }

        strcpy(respns, recvline);
    }

    // if n is negative then error
    if (n < 0)
    {
        printf("Read error");
    }

    if (!strcmp(recvline, "exit\n") )
    {
        // write to client
        sprintf((char *)buff, "exit\n");
        write(fd, (char *)buff, strlen((char *)buff));

        printf("\n[Client %s:%d disconnected]\n", ip, port);
        return 0;
    }
    else if (!strcmp(recvline, "exit\r\n"))
    {
        // write to client
        sprintf((char *)buff, "exit\r\n");
        write(fd, (char *)buff, strlen((char *)buff));

        printf("\n[Client %s:%d disconnected]\n", ip, port);
        return 0;
    }
    else
    {
        // write to client
        sprintf((char *)buff, "Server Responded\n");
        write(fd, (char *)buff, strlen((char *)buff));
    }
}