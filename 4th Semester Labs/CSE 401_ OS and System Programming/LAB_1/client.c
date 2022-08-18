#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h> // for sockaddr_in
#include <string.h>

#define PORT 8080
#define MAXSIZE 1024
#define BACKLOG 10 // how many pending connections queue will hold

void client()
{
    // variable declaration
    int sock_fd;                                             // server and client file descriptors
    struct sockaddr_in server_addr;                          // server address information
    char buffer[MAXSIZE] = {0};                              // buffer for receiving and sending data
    char message[] = "Client is sending message to server!"; // message to send to client

    // socket creation
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;         // host byte order
    server_addr.sin_port = htons(PORT);       // network byte order
    server_addr.sin_addr.s_addr = INADDR_ANY; // automatically fill with my IP

    // request connection
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Connection Failed");
        return -1;
    }
    printf("Client: Connected to server\n");
 
    // Handling multple client-----------------------------------------------------------
    // For keeping the connection open and sending messages to server
    
    while (1)
    {
        // message to send to server
        char mymessage[MAXSIZE];
        printf("\nEnter your message: ");
        // fgets(mymessage, MAXSIZE, stdin);
        scanf("%[^\n]", mymessage);

        // send message to server
        send(sock_fd, mymessage, sizeof(mymessage), 0);
        printf("Client: Message sent to server\n");

        // receive message from server
        recv(sock_fd, buffer, MAXSIZE, 0);
        printf("Server: %s\n", buffer);
    }

    close(sock_fd);
}

int main()
{
    client();
}
