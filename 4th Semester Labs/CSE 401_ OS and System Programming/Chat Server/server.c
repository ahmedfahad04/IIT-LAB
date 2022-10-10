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

#define MYPORT 8080
#define BACKLOG 10   // how many pending connections queue will hold
#define MAXLINE 4096 // max number of bytes we can get at once

pthread_mutex_t mutexClient;

struct client_info
{
    int id;
    int sockfd;
    char *username;
    int activestatus;

} clients[BACKLOG];

void *serverhandle(void *); // the thread function
void sendall(int fd, char *user);
int senderformat(char *msg);
void sendtouser(int fd, char *sendermsg);
char *formattedmessage(char *msg, char *user);
int errmsg(int response, char *msg);

int count = 0;
char singleuser[MAXLINE];
char singleusermsg[MAXLINE];
char multiusermsg[MAXLINE];

int errmsg(int rval, char *msg)
{
    if (rval < 0)
    {
        perror(msg);
        exit(1);
    }
    return rval;
}

char *formattedmessage(char *msg, char *user)
{
    char *msgformat = malloc(500);
    strcat(msgformat, "[");
    strcat(msgformat, user);
    strcat(msgformat, "] : ");
    strcat(msgformat, msg);
    strcat(msgformat, "\n");

    return msgformat;
}

int senderformat(char *msg)
{
    if (msg[0] == '@')
    {
        int i, j, k;
        int len = strlen(msg);

        bzero(singleuser, MAXLINE);
        bzero(singleusermsg, MAXLINE);

        // extract user name
        for (i = 1; i < len; i++)
        {
            if (msg[i] == ' ')
                break;
            singleuser[i - 1] = msg[i];
        }
        singleuser[i] = '\0';

        // extract message
        j = i + 1;
        for (k = 0; k < len; k++)
        {
            singleusermsg[k] = msg[j];
            j++;
        }
        singleusermsg[k] = '\0';

        // for server status only
        printf("NAME: %s\n", singleuser);
        printf("MSG: %s\n", singleusermsg);

        // check user type
        if (!strcmp(singleuser, "all"))
        {
            bzero(multiusermsg, MAXLINE);
            strcpy(multiusermsg, singleusermsg);
            printf("UPDATED MSG: %s\n", multiusermsg);
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

void sendall(int fd, char *user)
{
    printf("BULK WRITER...\n");

    // formatted message
    char *message = formattedmessage(multiusermsg, user);

    // send to all
    pthread_mutex_lock(&mutexClient);
    for (int i = 1; i <= count; i++)
    {
        if (clients[i].sockfd != fd && clients[i].activestatus && clients[i].sockfd != -1)
        {
            // send message
            errmsg(write(clients[i].sockfd, message, strlen(message)), "ERROR writing to socket");
        }
    }
    pthread_mutex_unlock(&mutexClient);
}

void sendtouser(int senderfd, char *sendername)
{
    printf("SINGLE WRITER...\n");
    int byte = 0, i;

    // formatted the message
    char *message = formattedmessage(singleusermsg, sendername);

    // send msg to particular user based on fd
    pthread_mutex_lock(&mutexClient);
    for (i = 1; i <= count; i++)
    {
        if (!strcmp(singleuser, clients[i].username) && clients[i].sockfd != -1) // sockfd = -1 means inactive user
        {
            printf("SENDING MESSAGE TO FD %d\n", clients[i].sockfd);
            byte = write(clients[i].sockfd, message, strlen(message));
            printf("TOTAL DATA SENT...%d bytes\n", byte);

            if (byte < 0)
            {
                perror("ERROR writing to socket");
                exit(1);
            }
        }
    }

    if (byte == 0)
    {
        printf("INVALID USER \"%s\"\n", singleuser);
        strcat(singleuser, " is not an active user\n");
        write(senderfd, singleuser, strlen(singleuser));
    }
    pthread_mutex_unlock(&mutexClient);
}

void sendmessage(int fd, char *msg, char *user)
{
    bzero(multiusermsg, MAXLINE);
    strcpy(multiusermsg, msg);
    int rvalue = senderformat(msg);

    if (rvalue == 1)
    {
        printf("SENDING TO USER...\n");
        sendtouser(fd, user);
    }
    else
    {
        printf("SENDING TO ALL...\n");
        sendall(fd, user);
    }
}

void *serverhandle(void *socket_struct)
{
    int n;
    char *str, buffer[MAXLINE], buffer2[MAXLINE], *tmp;

    // Get the socket descriptor
    struct client_info *client = (struct client_info *)socket_struct;
    int sock = client->sockfd;
    int clno = client->id;

    // read the client name
    bzero(buffer, MAXLINE);
    if (read(sock, buffer, MAXLINE - 1) < 0)
    {
        perror("ERROR reading from socket");
        exit(1);
    }

    // save username to the client struct
    printf("USER: %s\n", buffer);
    clients[clno].username = buffer;
    printf("[Client %d connected] & sockfd = %d\n", clno, sock);

    // send welcome message
    tmp = malloc(100);
    strcat(tmp, buffer);
    strcat(tmp, " has joined the chat room...\n");
    sendmessage(sock, tmp, "SERVER");

    while (1)
    {

        printf("\nWAITING FOR CLIENTS RESPONSE...\n");
        bzero(buffer2, MAXLINE);
        if (read(sock, buffer2, MAXLINE - 1) < 0)
        {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("[%s]: %s\n", clients[clno].username, buffer2);

        // blank data
        if (strlen(buffer2) == 0)
            break;

        if (!strcmp(buffer2, "\n")) // if client sends only enter
            continue;

        // exit message
        if (!strcmp(buffer2, "exit\n"))
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

            printf("Client %d: %s disconnected...\n", clients[clno].id, clients[clno].username);

            // send exit status to client
            int len = strlen(buffer2);
            buffer2[len - 1] = '\0';
            write(sock, buffer2, strlen(buffer2));

            bzero(buffer2, MAXLINE);
            read(sock, buffer2, MAXLINE - 1);
        }

        /* if we jump in between to another function of read and write, then your server buffer might wait/get stuck for next input
        so very be careful...*/

        printf("START SENDING...\n");
        sendmessage(sock, buffer2, clients[clno].username);
        printf("FINISH SENDING...\n");
    }

    close(sock);
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{

    int sockfd, new_sockfd, enable = 1;
    struct sockaddr_in my_addr;    // my address information
    struct sockaddr_in their_addr; // connector's address information
    int sin_size;
    pthread_t thread_id;
    char uname[MAXLINE + 1];

    // mutex initialization
    pthread_mutex_init(&mutexClient, NULL);

    // create socket
    errmsg((sockfd = socket(AF_INET, SOCK_STREAM, 0)), "ERROR opening socket");

    // set socket options
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));

    bzero((char *)&my_addr, sizeof(my_addr)); // zero the rest of the struct
    my_addr.sin_family = AF_INET;             // host byte order
    my_addr.sin_addr.s_addr = INADDR_ANY;     // automatically fill with my IP
    my_addr.sin_port = htons(MYPORT);         // short, network byte order

    // bind socket
    errmsg(bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)), "ERROR on binding");

    // listen
    errmsg(listen(sockfd, BACKLOG), "ERROR on listen");
    printf("Server is listening on port %d\n", MYPORT);

    for (int i = 0; i < BACKLOG; i++)
    {
        // accept new connection
        sin_size = sizeof(struct sockaddr_in);
        errmsg((new_sockfd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)), "ERROR on accept");

        printf("\nserver: got connection from %s:%d\n", inet_ntoa(their_addr.sin_addr), their_addr.sin_port);

        // define client info
        count++;
        clients[count].id = i + 1;
        clients[count].sockfd = new_sockfd;
        clients[count].username = uname;
        clients[count].activestatus = 1;

        // start child thread
        pthread_mutex_lock(&mutexClient);
        errmsg(pthread_create(&thread_id, NULL, serverhandle, (void *)&clients[count]), "ERROR create thread");
        pthread_mutex_unlock(&mutexClient);
    }

    pthread_detach(thread_id);

    close(sockfd);
    pthread_mutex_destroy(&mutexClient);
}
