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
 *   2. http://www.mario-konrad.ch/blog/programming/multithread/tutorial-04.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MYPORT 5050     // the port users will be connecting to
#define BACKLOG 10      // how many pending connections queue will hold
#define MAXDATASIZE 256 // max number of bytes we can get at once

void *dostuff(void *);  // the thread function

int main(void)
{
    int sockfd, new_sockfd;        // listen on sockfd, new connection on new_sockfd
    struct sockaddr_in my_addr;    // my address information
    struct sockaddr_in their_addr; // connector's address information
    int sin_size;
    pthread_t thread_id;

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

        // start child thread
        if (pthread_create(&thread_id, NULL, dostuff, (void *)&new_sockfd) < 0)
        {
            perror("ERROR create thread");
            exit(1);
        }

        pthread_detach(thread_id); // don't track it

    } /* end of while */

    close(sockfd);
    return 0;
}

void *dostuff(void *socket_desc)
{
    int n;
    char *str, buffer[MAXDATASIZE];
    // Get the socket descriptor
    int sock = *(int *)socket_desc;

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

    close(sock);
    pthread_exit(NULL);
}
