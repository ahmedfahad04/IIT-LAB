/*
 * server.c -- a stream socket server demo
 */

/*
 * The steps involved in establishing a socket on the server side are as follows:
 *  1. Create a socket with the socket() system call
 *  2. Bind the socket to an address using the bind() system call. For a server socket
 *     on the Internet, an address consists of a port number on the host machine.
 *  3. Listen for connections with the listen() system call
 *  4. Accept a connection with the accept() system call. This call typically blocks
 *     until a client connects with the server.
 *  5. Send and receive data
 *
 *  Ref:
 *   1. https://www.linuxhowtos.org/C_C++/socket.htm
 *   2. https://www.tutorialspoint.com/unix_sockets/socket_server_example.htm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MYPORT 5050     // the port users will be connecting to
#define BACKLOG 10      // how many pending connections queue will hold
#define MAXDATASIZE 256 // max number of bytes we can get at once

void dostuff(int); // function prototype

int main(void)
{
    int sockfd, new_sockfd;        // listen on sockfd, new connection on new_sockfd
    struct sockaddr_in my_addr;    // my address information
    struct sockaddr_in their_addr; // connector's address information
    int sin_size, pid;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *)&my_addr, sizeof(my_addr)); // zero the rest of the struct

    my_addr.sin_family = AF_INET;         // host byte order
    my_addr.sin_addr.s_addr = INADDR_ANY; // automatically fill with my IP
    my_addr.sin_port = htons(MYPORT);     // short, network byte order

    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) < 0)
    {
        perror("ERROR on binding");
        exit(1);
    }

    if (listen(sockfd, BACKLOG) < 0)
    {
        perror("ERROR on listen");
        exit(1);
    }

    sin_size = sizeof(struct sockaddr_in);

    while (1)
    {
        if ((new_sockfd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) < 0)
        {
            perror("ERROR on accept");
            exit(1);
        }
        printf("server: got connection from %s\n", inet_ntoa(their_addr.sin_addr));

        pid = fork(); // Create child process
        if (pid < 0)
        {
            perror("ERROR on fork");
            exit(1);
        }

        if (pid == 0)
        {                  // This is the child process
            close(sockfd); // child doesn't need the listener
            dostuff(new_sockfd);
            exit(0);
        }
        else
            close(new_sockfd); // parent doesn't need this
    }                          /* end of while */

    return 0;
}

void dostuff(int sock)
{
    int n;
    char *str, buffer[MAXDATASIZE];

    str = "Please enter the message: ";
    if (write(sock, str, strlen(str)) < 0)
    {
        perror("ERROR writing to socket");
        exit(1);
    }

    bzero(buffer, MAXDATASIZE);
    if (read(sock, buffer, MAXDATASIZE - 1) < 0)
    {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Here is the message: %s\n", buffer);

    str = "I got your message \n";
    if (write(sock, str, strlen(str)) < 0)
    {
        perror("ERROR writing to socket");
        exit(1);
    }

    exit(0);
}
