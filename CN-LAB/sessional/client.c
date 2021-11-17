#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>

#define MYPORT 6001
int mySocket;
struct sockaddr_in serverAddress, clientAddress;
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
    if (connect(mySocket, (struct sockaddr *)&clientAddress, (socklen_t)sizeof(clientAddress)) == -1)
    {
        printf("connect error()!\n");
        exit(-1);
    }
}

void closeConnection()
{
    close(mySocket);
    printf("\n*** Connection closed! ***\n\n");
}

void main()
{
    for (int i = 0; i < 4; i++)
    {
        char c;
        connectToServer();
        scanf("%c%*c", &c);
        send(mySocket, &c, sizeof(c), 0);
        closeConnection();
        srand(time(0));
    }
    char cs[4];
    connectToServer();
    recv(mySocket, &cs, sizeof(cs), 0);
    printf("Received string: %s", cs);
    closeConnection();
}