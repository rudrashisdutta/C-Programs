#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
void main()
{
    int sockfd;
    int MYPORT = 5000;
    struct sockaddr_in my_addr;
    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        printf("Socket failed");
    else
        printf("Socket created");
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(MYPORT);
    my_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(&(my_addr.sin_zero), '\0', 8);
    int b = bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr));
    if (b == -1)
        printf("\nBind failed");
    else
        printf("\nBind created");
}