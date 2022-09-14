#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BACKLOG 10  // how many pending connections queue will hold
#define MAXLINE 256 // max number of bytes we can get at once

struct client_info {
    int *id;
    int *sockfd;
} clients[BACKLOG];

void *dostuff(void *); // the thread function
void *serverActivity(void *sockfd);
int count = 0, loopcontrol = 0;

int main(int argc, char **argv)
{
    
    int sockfd, new_sockfd, MYPORT, enable = 1; // listen on sockfd, new connection on new_sockfd
    struct sockaddr_in my_addr;                 // my address information
    struct sockaddr_in their_addr;              // connector's address information
    int sin_size;
    pthread_t thread_id;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));

    bzero((char *)&my_addr, sizeof(my_addr)); // zero the rest of the struct
    MYPORT = atoi(argv[1]);
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
    printf("Server is listening on port %d\n", MYPORT);

    for(int i=0; i<BACKLOG; i++)
    {

        if ((new_sockfd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) < 0)
        {
            perror("ERROR on accept");
            exit(1);
        }
        printf("server: got connection from %s\n", inet_ntoa(their_addr.sin_addr));
        clients[i].id = (int*) malloc(sizeof(int));
        *clients[i].id = i;
        clients[i].sockfd = &new_sockfd; 

        // start child thread
        if (pthread_create(&thread_id, NULL, dostuff, (void *)&clients) < 0)
        {
            perror("ERROR create thread");
            exit(1);
        }

    }
    /* end of while */
    for(int i=0; i<BACKLOG; i++) pthread_join(*clients[i].id, NULL);

    close(sockfd);
    return 0;
}

void *dostuff(void *socket_struct)
{
    int n;
    char *str, buffer[MAXLINE];
    // Get the socket descriptor
    struct client_info *client = (struct client_info*) socket_struct;
    int sock = *client->sockfd;
    // int sock = *(int *)socket_struct;

    printf("[Client %d connected] & sockfd = %d\n", clients->id, sock);

    while (1)
    {
        str = "Please enter the message: ";
        if (write(sock, str, strlen(str)) < 0)
        {
            perror("ERROR writing to socket");
            exit(1);
        }

        bzero(buffer, MAXLINE);
        if (read(sock, buffer, MAXLINE - 1) < 0)
        {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Here is the message: %s\n", buffer);

        if (!strcmp(buffer, "exit\n"))
        {
            // write to client
            // sprintf((char *)buffer, "exit\n");
            write(sock, buffer, strlen(str));

            // printf("\n[Client %s:%d disconnected]\n", ip, port);
            pthread_exit(NULL);

            return 0;
        }
        else if (!strcmp(buffer, "exit\r\n"))
        {
            // write to client
            // sprintf((char *)buffer, "exit\r\n");
            write(sock, buffer, strlen(str));

            // printf("\n[Client %s:%d disconnected]\n", ip, port);
            pthread_exit(NULL);

            return 0;
        }
    }
    // close(sock);
    // pthread_exit(NULL);
}
