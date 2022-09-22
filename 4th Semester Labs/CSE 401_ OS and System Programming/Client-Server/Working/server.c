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
    int activestatus;

} clients[BACKLOG];

void *dostuff(void *); // the thread function
void *serverActivity(void *sockfd);
void sendall(int fd, char *str);
void showActiveStatus(int fd, char *str);
int processSenderName(char *msg);
void sendtoUser(char *user, char *msg);

int count = 0, loopcontrol = 0;
char *singleuser;

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

        // start child thread
        count++;
        clients[count].id = i + 1;
        clients[count].sockfd = new_sockfd;
        clients[count].username = uname;
        clients[count].activestatus = 1;

        // start child thread
        if (pthread_create(&thread_id, NULL, dostuff, (void *)&clients[count]) < 0)
        {
            perror("ERROR create thread");
            exit(1);
        }
    }

    /* end of while */
    pthread_detach(thread_id);

    close(sockfd);
    pthread_mutex_destroy(&mutexClient);
    return 0;
}

int processSenderName(char *msg)
{

    if (msg[0] == '@')
    {
        char *token = strtok(msg, " ");
        singleuser = strtok(token, "@");
        return 1;
    }
    else
    {
        return 0;
    }
}

// TODO: NEED to resolve
void showActiveStatus(int fd, char *str)
{
    printf("INSIDE 1..\n");
    char *status = malloc(100);

    pthread_mutex_lock(&mutexClient);
    for (int i = 1; i <= count; i++)
    {
        if (clients[i].sockfd == fd)
        {
            printf("ACTUAL INSIDE...\n");

            for (int i = 1; i <= count; i++)
            {
                printf("---Running %d---\n", i);
                sprintf(status, "%d %s %d", clients[i].id, clients[i].username, clients[i].activestatus);
                write(clients[i].sockfd, status, strlen(status));
                // printf("Client %d, Socket %d, Name %s -> %d\n", clients[i].id, clients[i].sockfd, clients[i].username, clients[i].activestatus);
            }
        }
    }
    pthread_mutex_unlock(&mutexClient);
}

void sendall(int fd, char *str)
{
    printf("BULK WRITER...\n");

    pthread_mutex_lock(&mutexClient);
    for (int i = 1; i <= count; i++)
    {
        if (clients[i].sockfd != fd && clients[i].activestatus && clients[i].sockfd != -1)
        {
            if (write(clients[i].sockfd, str, strlen(str)) < 0)
            {
                perror("ERROR writing to socket");
                exit(1);
            }
        }
    }
    pthread_mutex_unlock(&mutexClient);
}

void sendtoUser(char *user, char *msg)
{

    int fd = 0;
    printf("USER: %s\n", user);
    // find fd of the user
    for (int i = 1; i <= count; i++)
    {
        if (!strcmp(user, clients[i].username))
        {
            fd = clients[i].sockfd;
            printf("SENDING MESSAGE...\n");
            pthread_mutex_lock(&mutexClient);
            if (write(clients[i].sockfd, msg, strlen(msg)) < 0)
            {
                perror("ERROR writing to socket");
                exit(1);
            }
            pthread_mutex_unlock(&mutexClient);
            bzero(msg, MAXLINE + 1);
            break;
        }
    }
    printf("NEW FD: %d\n", fd);
}
void *dostuff(void *socket_struct)
{
    int n;
    char *str, buffer[MAXLINE], buffer2[MAXLINE], *buffer3;
    char *newmsg;

    // Get the socket descriptor
    struct client_info *client = (struct client_info *)socket_struct;
    int sock = client->sockfd;
    int clno = client->id;

    bzero(buffer, MAXLINE);
    if (read(sock, buffer, MAXLINE - 1) < 0)
    {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("USER: %s\n", buffer);
    clients[clno].username = buffer;

    printf("[Client %d connected] & sockfd = %d\n", clno, sock);

    while (1)
    {
        // printf("S-Read\n");
        bzero(buffer2, MAXLINE);
        if (read(sock, buffer2, MAXLINE - 1) < 0)
        {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("[%s]: %s\n", clients[clno].username, buffer2);

        if (strlen(buffer2) == 0)
            break;

        if (!strcmp(buffer2, "exit"))
        {
            // write to client
            for (int i = 1; i <= count; i++)
            {
                if (clients[i].sockfd == sock)
                {
                    clients[i].activestatus = 0;
                    clients[i].sockfd = -1;
                }
            }

            // send exit status to client
            write(sock, buffer2, strlen(buffer2));

            // got client exit message to send to all
            bzero(buffer2, MAXLINE);
            read(sock, buffer2, MAXLINE - 1);
        }

        // if (!strcmp(buffer2, "LIST"))
        // {
        //     showActiveStatus(sock, buffer2);
        //     for (int i = 1; i <= count; i++)
        //     {
        //         printf("Client %d, Socket %d, Name %s -> %d\n", clients[i].id, clients[i].sockfd, clients[i].username, clients[i].activestatus);
        //     }
        // }
        // else
        // {
        // printf("Send all user");
        // }

        /* if we jump in between of read and write, then your server buffer might wait for next input
        so very be careful...*/

        // TODO: FIX SINGLE USER ISSUE
        int flag = 0;
        if (buffer2[0] == '@')
        {
            char *token = strtok(buffer2, " ");
            singleuser = strtok(token, "@");
            strcat(singleuser, "\0");
            printf("Single user: %s\n", singleuser);
            flag = 1;
        }



        if (flag == 1)
        {
            sendtoUser(singleuser, buffer2);
            bzero(buffer2, MAXLINE);
        }
        else
        {
            strcat(buffer2, "---");
            strcat(buffer2, clients[clno].username);
            strcat(buffer2, "\n");
            sendall(sock, buffer2);
        }
    }

    close(sock);
    pthread_exit(NULL);
}
