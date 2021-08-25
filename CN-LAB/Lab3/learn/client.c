#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netinet/ip.h>
#include<netinet/in.h>

void main(){
    int client_socket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(client_socket == -1){
        
    }
}