#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h> // for sockaddr_in
#include <string.h>

#define PORT 8080
#define MAXSIZE 1024
#define BACKLOG 10 // how many pending connections queue will hold

int main()
{

    // variable declaration
    int server_fd, client_fd;                         // server and client file descriptors
    struct sockaddr_in myaddr;                        // server address information
    char buffer[MAXSIZE]= {0};                        // buffer for receiving and sending data
    char message[] = "Server has got clients message";// message to send to client
    int opt = 1;

    // socket creation
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    myaddr.sin_family = AF_INET;         // host byte order
    myaddr.sin_addr.s_addr = INADDR_ANY; // automatically fill with my IP
    myaddr.sin_port = htons(PORT);       // short, network byte order

    // bind socket
    if (bind(server_fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen on socket
    if (listen(server_fd, BACKLOG) < 0)
    {
        perror("ERROR on listen");
        exit(1);
    }
    printf("Server is listening on port %d\n", PORT);

    int address_length = sizeof(struct sockaddr_in);
    if ((client_fd = accept(server_fd, (struct sockaddr *)&myaddr, &address_length)) < 0)
    {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    printf("Server: connection accepted\n");

    recv(client_fd, buffer, MAXSIZE, 0);
    printf("Client: %s", buffer);

    send(client_fd, message, sizeof(message), 0);
    printf("Server: message sent\n");

    // close socket
    close(client_fd);
    close(server_fd);
}
