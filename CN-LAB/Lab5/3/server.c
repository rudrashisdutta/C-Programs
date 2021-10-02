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
    printf("Server coming Online .... %d%d\n", server_socket, i);
    listen(server_socket, 5);
    int client_socket;
    len = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &len);
    int buf[5];
    int j;
    recv(client_socket, buf, 5 * sizeof(int), 0);
    int c, d, t;
    for (c = 0; c < 5 - 1; c++)
    {
        for (d = 0; d < 5 - c - 1; d++)
        {
            if (buf[d] > buf[d + 1])
            { /* Swapping */
                t = buf[d];
                buf[d] = buf[d + 1];
                buf[d + 1] = t;
            }
        }
    }
    for (j = 0; j < 5; j++)
    {
        printf("%d\n", buf[j]);
    }
    close(server_socket);
}