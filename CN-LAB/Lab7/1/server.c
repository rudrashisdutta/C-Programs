#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>

#define MYPORT 9090
int serverSocket, clientSocket;
struct sockaddr_in serverAddress, clientAddress;
void connectToClient();
void closeConnection();

int main(){
    connectToClient();

    char buffer[256];
    int n = recv(clientSocket, buffer, sizeof(buffer), 0);
    for(int i=0; i<n; ++i){
        char temp = buffer[i];
        if(temp >= 97 && temp <= 122){
            temp -= 32;
        }
        send(clientSocket, (const void*)&temp, sizeof(temp), 0);
    }

    closeConnection();
    return 0;
}

void connectToClient(){
    if((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        printf("socket() error!\n");
        exit(-1);
    }
    printf("Socket created successfully!\n");

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(MYPORT);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if(bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1){
        printf("bind() error!\n");
        exit(-1);
    }
    printf("Socket binded successfully!\n");

    if(listen(serverSocket, 2) == -1){
        printf("listen() error!\n");
        exit(-1);
    }
    printf("Listening at port %d for connection request...\n",MYPORT);

    int length = sizeof(clientAddress);
    if((clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, (socklen_t*)&length)) == -1){
        printf("accept() error!\n");
        exit(-1);
    }
    printf("Connection request accepted from client!\n");

    printf("\n*** TCP connection established successfully! ***\n\n");
    return;
}

void closeConnection(){
    close(serverSocket);
    close(clientSocket);
    printf("\n*** Connection closed! ***\n\n");
    return;
}