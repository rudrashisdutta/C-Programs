#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
    int server_socket;
    int i, len;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serveraddr, client_address;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8800);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    i = bind(server_socket, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    printf("SERVER ONLINE .... %d%d\n", server_socket, i);
    listen(server_socket, 5);
    int client_socket;
    len = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &len);
    int buffer[5];
    int j;

    recv(client_socket, buffer, 5 * sizeof(int), 0);
    for (i = 0; i < 5; i++)
    {
        if (buffer[i] % 2 == 0)
        {
            printf("%d is the even no at pos %d\n", buffer[i], i + 1);
        }
        else
        {
            printf("%d is the odd no at pos %d\n", buffer[i], i + 1);
        }
    }
    close(server_socket);
}
