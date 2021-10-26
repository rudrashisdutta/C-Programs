#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>

#define MYPORT 6002
int mySocket;
struct sockaddr_in serverAddress, clientAddress;
void connectToServer();
void closeConnection();

int main(){
    connectToServer();

    int size, *arr;
    printf("Enter array size : ");
    scanf("%d",&size);
    arr = (int*)malloc(size*sizeof(int));
    printf("Enter %d elements :\n",size);
    for(int i=0; i<size; ++i){
        scanf("%d",&arr[i]);
    }

    send(mySocket, arr, size*sizeof(int), 0);
    printf("Array sent to server.\n\n");
    
    int buffer, ans[size];
    for(int i=0; i<size/2; ++i){
        recv(mySocket, &ans[i], sizeof(ans[0]), 0); 
    }

    printf("New array received from server :\n");
    for(int i=0; i<size/2; ++i){
        printf("%d ",ans[i]);
    }
    printf("\n");
    closeConnection();
    return 0;
}

void connectToServer(){
    if((mySocket = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        printf("socket() error!\n");
        exit(-1);
    }
    printf("Socket created successfully!\n");

    clientAddress.sin_family = AF_INET;
    clientAddress.sin_port = htons(MYPORT);
    clientAddress.sin_addr.s_addr = INADDR_ANY;

    printf("Sending connect request at port %d...\n",MYPORT);
    if(connect(mySocket, (struct sockaddr*)&clientAddress, (socklen_t)sizeof(clientAddress)) == -1){
        printf("connect error()!\n");
        exit(-1);
    }

    printf("\n*** TCP connection established successfully! ***\n\n");
    return;
}

void closeConnection(){
    close(mySocket);
    printf("\n*** Connection closed! ***\n\n");
    return;
}