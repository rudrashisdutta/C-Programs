#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define MYPORT 6001
int serverSocket, clientSocket;
struct sockaddr_in serverAddress, clientAddress;

void connectToClient()
{
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("socket() error!\n");
        exit(-1);
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(MYPORT);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1)
    {
        printf("bind() error!\n");
        exit(-1);
    }
}

void closeConnection()
{
    close(serverSocket);
    close(clientSocket);
    printf("\n*** Connection closed! ***\n\n");
}
void main()
{
    connectToClient();
    char cs[4];

    for (int i = 0; i < 4; i++)
    {
        if (listen(serverSocket, 2) == -1)
        {
            printf("listen() error!\n");
            exit(-1);
        }
        int length = sizeof(clientAddress);
        if ((clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, (socklen_t *)&length)) == -1)
        {
            printf("accept() error!\n");
            exit(-1);
        }
        char c;
        recv(clientSocket, &c, sizeof(c), 0);
        cs[i] = c;
    }
    if (listen(serverSocket, 2) == -1)
    {
        printf("listen() error!\n");
        exit(-1);
    }
    int length = sizeof(clientAddress);
    if ((clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, (socklen_t *)&length)) == -1)
    {
        printf("accept() error!\n");
        exit(-1);
    }
    send(clientSocket, cs, sizeof(cs), 0);
    closeConnection();
    close(serverSocket);
}