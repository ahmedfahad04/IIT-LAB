#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <sys/time.h>
#include <string.h>


#define SERVER_PORT 8080
#define MAXLINE 4096
#define SA struct sockaddr

int main(int argc, char **argv){

    int sockfd, n;
    int sendbytes;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE];
    char recvline[MAXLINE];

    // check for ip address
    if(argc != 2) {
        printf("usage: %s <server address>", argv[0]);
    }

    // create socket
    if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error while creating the socket!");
    }

    // set server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT); /* chat server */

    // convert ip address to binary
    if ( inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <=0 ){
        printf("inet_pton error for %s ", argv[1]);
    }

    // connect to server
    if( connect (sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0){
        printf("Connection Failed!");
    }    

    while(1){
        
        // copy message to sendline
        // fgets(sendline, MAXLINE, stdin);
        sprintf(sendline, "GET / HTTP/1.1\r\n\r\n");
        sendbytes = strlen(sendline);

        // send message to server
        if (write(sockfd, sendline, sendbytes) !=  sendbytes) {
            printf("Write Error");
        }

        // make recvline initialized to 0
        memset (recvline, 0, MAXLINE);

        // read message from server
        while ( (n = read(sockfd, recvline, MAXLINE-1) ) > 0){
            printf("%s", recvline);
        }

        // if n is negative then error
        if (n < 0) {
            printf("Read error");
        }

        exit(0);
    }
}