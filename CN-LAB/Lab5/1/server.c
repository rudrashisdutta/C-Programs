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
    char buf[50];
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serveraddr, client_address;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8800);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    i = bind(server_socket, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    printf("Server coming Online .... %d%d\n", server_socket, i);
    listen(server_socket, 5);
    int client_socket;
    len = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &len);
    int j;
    for (i = 0; i < 50; i++)
        buf[i] = '\0';
    recv(client_socket, buf, 50, 0);
    for (j = 0; j < 50; j++)
    {
        if ((buf[j] == 'A') || (buf[j] == 'E') || (buf[j] == 'I') || (buf[j] == 'O') || (buf[j] == 'U'))
        {
            printf("%c at %d\n", buf[j], j + 1);
        }
    }
    printf("%s\n", buf);
    close(server_socket);
}