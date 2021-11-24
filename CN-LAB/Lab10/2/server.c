#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#define MYPORT 9090
int mySocket;
struct sockaddr_in serverAddress, clientAddress;
int len = sizeof(clientAddress);
void connectToClient();
void closeConnection();

int main()
{
    connectToClient();

    char buffer[128];
    int l = sizeof(clientAddress);
    recvfrom(mySocket, &buffer, sizeof(buffer), 0, &clientAddress, &l);
    for (int i = 0; i < strlen(buffer); ++i)
    {
        buffer[i] ^= 32;
    }
    sendto(mySocket, &buffer, sizeof(buffer), 0, &clientAddress, l);

    closeConnection();
    return 0;
}

void connectToClient()
{
    if ((mySocket = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        printf("socket() error!\n");
        exit(-1);
    }
    printf("Socket created successfully!\n");

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(MYPORT);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(mySocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1)
    {
        printf("bind() error!\n");
        exit(-1);
    }
    printf("Socket binded successfully!\n");
    printf("Ready to send/receive data at port %d\n\n", MYPORT);
    return;
}

void closeConnection()
{
    close(mySocket);
    printf("\n*** Connection closed! ***\n\n");
    return;
}
