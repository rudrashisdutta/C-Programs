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
struct sockaddr_in serverAddress;
int len = sizeof(serverAddress);
void connectToServer();
void closeConnection();

int main()
{
    connectToServer();

    char buffer[128];
    printf("Enter a string : ");
    scanf("%s", buffer);
    int l = sizeof(serverAddress);
    sendto(mySocket, &buffer, sizeof(buffer), 0, &serverAddress, l);
    recvfrom(mySocket, &buffer, sizeof(buffer), 0, &serverAddress, &l);
    printf("%s\n", buffer);

    closeConnection();
    return 0;
}

void connectToServer()
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

    printf("Ready to send/receive data at port %d\n\n", MYPORT);
    return;
}

void closeConnection()
{
    close(mySocket);
    printf("\n*** Connection closed! ***\n\n");
    return;
}