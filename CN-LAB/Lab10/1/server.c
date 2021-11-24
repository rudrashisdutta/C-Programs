#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#define MYPORT 9000
int serverSocket, clientSocket;
struct sockaddr_in serverAddress, clientAddress;
void connectToClient();
void closeConnection();

int main()
{
    connectToClient();

    char buffer1[128], buffer2[128];
    recv(clientSocket, &buffer1, sizeof(buffer1), 0);
    int prev = 0, k = 0;
    for (int i = 0; i < strlen(buffer1); ++i)
    {

        if (buffer1[i] == ' ')
        {
            buffer2[k++] = buffer1[prev];
            buffer2[k++] = '.';
            buffer2[k++] = ' ';
            prev = i + 1;
        }
    }
    for (int i = prev; i < strlen(buffer1); ++i)
    {
        buffer2[k++] = buffer1[i];
    }
    buffer2[k] = '\0';
    send(clientSocket, &buffer2, sizeof(buffer2), 0);
    closeConnection();
    return 0;
}

void connectToClient()
{
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("socket() error!\n");
        exit(-1);
    }
    printf("Socket created successfully!\n");

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(MYPORT);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1)
    {
        printf("bind() error!\n");
        exit(-1);
    }
    printf("Socket binded successfully!\n");

    if (listen(serverSocket, 2) == -1)
    {
        printf("listen() error!\n");
        exit(-1);
    }
    printf("Listening at port %d for connection request...\n", MYPORT);

    int length = sizeof(clientAddress);
    if ((clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, (socklen_t *)&length)) == -1)
    {
        printf("accept() error!\n");
        exit(-1);
    }
    printf("Connection request accepted from client!\n");

    printf("\n*** TCP connection established successfully! ***\n\n");
    return;
}

void closeConnection()
{
    close(serverSocket);
    close(clientSocket);
    printf("\n*** Connection closed! ***\n\n");
    return;
}