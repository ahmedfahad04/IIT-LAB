#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <sys/time.h>
#include <string.h>

#define SERVER_PORT 8080
#define MAXLINE 4096
#define BACKLOG 10
#define SA struct sockaddr

char * serverActivity (int);

int main(int argc, char **argv)
{

    int listenfd, connfd, n;
    struct sockaddr_in servaddr;
    struct sockaddr_in their_addr;
   

    // create socket
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error while creating the socket!");
    }

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

    while (1)
    {

        struct sockaddr_in addr;
        socklen_t addr_len;
        char client_addr[MAXLINE + 1];
        int client_port;

        printf("Waiting for a connection on port %d\n", SERVER_PORT);
        fflush(stdout);

        // accept connection
        connfd = accept(listenfd, (SA *)&addr, &addr_len);
        inet_ntop(AF_INET, &(addr.sin_addr), client_addr, MAXLINE);
        printf("[Client %s:%d connected]\n", client_addr, addr.sin_port);


        // pid_t pid = fork();
        
        // if(pid < 0){
        //     printf("CHILD PROCESS NOT CREATED");
        //     exit(1);
        // }
        // if(pid == 0){
            while (1)
            {
                // if(pid == 0){
                    char response[MAXLINE];
                    printf("===> %s", serverActivity(connfd));
                    if(response == "exit") printf("Client %s:%d disconnected", client_addr, addr.sin_port);

                    // exit(0);
                // }
            // }
            }

        // else{
        //     printf("Parent Process");
        // }
    }

    close(connfd);
}

char *serverActivity(int fd)
{

    char buff[MAXLINE + 1];
    char recvline[MAXLINE + 1];
    int n;

    memset(recvline, 0, MAXLINE);

    // read message from client
    while ((n = read(fd, recvline, MAXLINE - 1)) > 0)
    {
        fprintf(stdout, "\n%s", recvline);

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

    sprintf((char *)buff, ">>");
    write(fd, (char *)buff, strlen((char *)buff));

    return buff;
}