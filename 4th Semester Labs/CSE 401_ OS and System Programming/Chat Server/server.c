#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BACKLOG 10      // how many pending connections queue will hold
#define MAXDATASIZE 256 // max number of bytes we can get at once

void *dostuff(void *); // the thread function
void errmsg(int returnvalue, char *msg);

int main(int argc, char *argv[])
{
    int sockfd, new_sockfd, MYPORT;        // listen on sockfd, new connection on new_sockfd
    struct sockaddr_in my_addr;    // my address information
    struct sockaddr_in their_addr; // connector's address information
    int sin_size;
    pthread_t thread_id;

    if(argc != 2){
        printf("usage: ./s <port>\n");
    }

    errmsg((sockfd = socket(AF_INET, SOCK_STREAM, 0)), "Socket Error");

    bzero((char *)&my_addr, sizeof(my_addr)); // zero the rest of the struct
    
    MYPORT = atoi(argv[1]);
    my_addr.sin_family = AF_INET;         // host byte order
    my_addr.sin_addr.s_addr = INADDR_ANY; // automatically fill with my IP
    my_addr.sin_port = htons(MYPORT);     // short, network byte order

    errmsg(bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)), "Bind Error");
    errmsg(listen(sockfd, BACKLOG), "Listen Error");

    sin_size = sizeof(struct sockaddr_in);
    printf("Server is listening on port %d\n", MYPORT);


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

    // write to the client
    str = "Please enter the message: ";
    errmsg(write(sock, str, strlen(str)), "Write error");

    // read from client
    bzero(buffer, MAXDATASIZE);
    errmsg(read(sock, buffer, MAXDATASIZE - 1), "Reading Error");

    printf("Here is the message: %s\n", buffer);

    // again write to client
    str = "I got your message \n";
    errmsg(write(sock, str, strlen(str)), "Write error");
    
    close(sock);
    pthread_exit(NULL);
}


void errmsg(int returnvalue, char *msg){

    if(returnvalue < 0) {
        printf("%s", msg);
        exit(1);
    }
}
