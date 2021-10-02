#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
int main()
{
    int sock;
    int i;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8800);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    i = connect(sock, (struct sockaddr *)&server_address, sizeof(server_address));
    int buf[5] = {12, 43, 2, 6, 0};
    send(sock, buf, 5 * sizeof(int), 0);
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", buf[i]);
    }
    close(sock);
    return 0;
}