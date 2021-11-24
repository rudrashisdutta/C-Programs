#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#define MYPORT 9000
int mySocket;
struct sockaddr_in serverAddress, clientAddress;
void connectToServer();
void closeConnection();

int main()
{
    connectToServer();

    char buffer1[128], buffer2[128];
    printf("Enter name : ");
    // scanf("%[^\n]",buffer1);
    gets(buffer1);
    send(mySocket, &buffer1, sizeof(buffer1), 0);
    recv(mySocket, &buffer2, sizeof(buffer2), 0);
    puts(buffer2);
    printf("\n");

    closeConnection();
    return 0;
}

void connectToServer()
{
    if ((mySocket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("socket() error!\n");
        exit(-1);
    }
    printf("Socket created successfully!\n");

    clientAddress.sin_family = AF_INET;
    clientAddress.sin_port = htons(MYPORT);
    clientAddress.sin_addr.s_addr = INADDR_ANY;

    printf("Sending connect request at port %d...\n", MYPORT);
    if (connect(mySocket, (struct sockaddr *)&clientAddress, (socklen_t)sizeof(clientAddress)) == -1)
    {
        printf("connect error()!\n");
        exit(-1);
    }

    printf("\n*** TCP connection established successfully! ***\n\n");
    return;
}

void closeConnection()
{
    close(mySocket);
    printf("\n*** Connection closed! ***\n\n");
    return;
}