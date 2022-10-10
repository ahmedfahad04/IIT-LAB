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
#define BACKLOG 10  // how many pending connections queue will hold
#define MAXLINE 256 // max number of bytes we can get at once

pthread_mutex_t mutexClient;

struct client_info
{
    int id;
    int sockfd;
    char *username;
    char *state;

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
    char uname[MAXLINE + 1];

    pthread_mutex_init(&mutexClient, NULL);

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

    for (int i = 0; i < BACKLOG; i++)
    {

        if ((new_sockfd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) < 0)
        {
            perror("ERROR on accept");
            exit(1);
        }

        printf("server: got connection from %s\n", inet_ntoa(their_addr.sin_addr));

        pthread_mutex_lock(&mutexClient);
        count++;
        clients[count].id = i + 1;
        clients[count].sockfd = new_sockfd;

        // start child thread
        if (pthread_create(&thread_id, NULL, dostuff, (void *)&clients[count]) < 0)
        {
            perror("ERROR create thread");
            exit(1);
        }
        pthread_mutex_unlock(&mutexClient);
    }
    /* end of while */
    for (int i = 1; i <= BACKLOG; i++)
        pthread_join(clients[i].id, NULL);

    close(sockfd);
    pthread_mutex_destroy(&mutexClient);
    return 0;
}


void *dostuff(void *socket_struct)
{
    int n;
    char *str, buffer[MAXLINE], buffer2[MAXLINE];
    char *temp;

    // Get the socket descriptor
    struct client_info *client = (struct client_info *)socket_struct;
    int sock = client->sockfd;
    int clno = client->id;

    printf("[Client %d connected] & sockfd = %d\n", clno, sock);

    int i = 0;
    while (1)
    {
        if (i == 0)
        {
            str = "UserName: ";
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

            clients[clno].id = clno;
            clients[clno].sockfd = sock;
            clients[clno].username = (char *)malloc(sizeof(char) * MAXLINE);
            clients[clno].username = buffer;
            clients[clno].username[sizeof(buffer)] = '\0';

            printf("USER NAME ADDED...%s\n", clients[clno].username);
        }
        else
        {

            str = "Please enter the message: ";
            if (write(sock, str, strlen(str)) < 0)
            {
                perror("ERROR writing to socket");
                exit(1);
            }

            bzero(buffer2, MAXLINE);
            if (read(sock, buffer2, MAXLINE - 1) < 0)
            {
                perror("ERROR reading from socket");
                exit(1);
            }

            printf("[%s]: %s\n", clients[clno].username, buffer2);

            if (!strcmp(buffer2, "exit"))
            {
                // write to client
                // sprintf((char *)buffer, "exit\n");
                fflush(stdin);
                for (int i = 1; i <= count; i++)
                {
                    if(clients[i].sockfd == sock){ 
                        char *msg = "DISCONNECTED!";
                        clients[i].state = msg;
                    }
                }
                write(sock, buffer2, strlen(str));


                // printf("\n[Client %s:%d disconnected]\n", ip, port);
                // pthread_exit(NULL);

                return 0;
            }
            else if (!strcmp(buffer2, "exit\r\n"))
            {
                // write to client
                // sprintf((char *)buffer, "exit\r\n");
                write(sock, buffer2, strlen(str));

                // printf("\n[Client %s:%d disconnected]\n", ip, port);
                // pthread_exit(NULL);

                return 0;
            }
            else if (!strcmp(buffer2, "LIST"))
            {
                for (int i = 1; i <= count; i++)
                {
                    printf("Client %d, Socket %d, Name %s -> %s\n", clients[i].id, clients[i].sockfd, clients[i].username, clients[i].state);
                }
            }
        }
        i++;
    }
    // close(sock);
    // pthread_exit(NULL);
}
