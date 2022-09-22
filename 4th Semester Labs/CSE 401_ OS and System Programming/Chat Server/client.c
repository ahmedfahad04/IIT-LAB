
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXDATASIZE 256 // max number of bytes we can get at once

int main(int argc, char *argv[])
{
    int sockfd, numbytes, PORT;
    char buf[MAXDATASIZE];
    struct hostent *server;
    struct sockaddr_in server_addr; // connector's address information

    if (argc != 3)
    {
        printf("usage: ./c <ip> <port>\n");
        exit(1);
    }

    if ((server = gethostbyname(argv[1])) == NULL)
    { // get the host info
        printf("ERROR, no such host\n");
        exit(0);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("ERROR opening socket");
        exit(0);
    }

    bzero((char *)&server_addr, sizeof(server_addr)); // zero the rest of the struct
    server_addr.sin_family = AF_INET;                 // host byte order
    server_addr.sin_port = htons(PORT);               // short, network byte order
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) < 0)
    {
        perror("ERROR connecting");
        exit(0);
    }

    // read from server
    bzero(buf, MAXDATASIZE);
    if ((numbytes = read(sockfd, buf, MAXDATASIZE - 1)) < 0)
    {
        perror("ERROR reading from socket");
        exit(0);
    }
    printf("%s", buf);

    // write to server
    bzero(buf, MAXDATASIZE);
    scanf("%[^\n]%*c", buf);

    if (write(sockfd, buf, strlen(buf)) < 0)
    {
        perror("ERROR writing to socket");
        exit(0);
    }

    // read from server
    bzero(buf, MAXDATASIZE);
    if ((numbytes = read(sockfd, buf, MAXDATASIZE - 1)) < 0)
    {
        perror("ERROR reading from socket");
        exit(0);
    }

    buf[numbytes] = '\0';

    printf("Received: %s", buf);

    close(sockfd);

    return 0;
}
