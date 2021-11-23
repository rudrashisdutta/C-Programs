#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
int main()
{
    int i, sockfd;
    char buf[100];
    struct sockaddr_in sa_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    sa_addr.sin_family = AF_INET;
    sa_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa_addr.sin_port = htons(6000);
    memset(sa_addr.sin_zero, '\0', sizeof sa_addr.sin_zero);
    i = connect(sockfd, (struct sockaddr *)&sa_addr, sizeof(sa_addr));
    if (i == -1)
    {
        printf("failed!");
        exit(0);
    }
    printf("Enter your full name: ");
    fgets(buf, 100, stdin);
    send(sockfd, buf, 100, 0);
    recv(sockfd, buf, 100, 0);
    int ctr = sizeof(buf) / sizeof(char);
    for (int i = 0; i < ctr; i++)
    {
        printf("%c", buf[i]);
    }
    close(sockfd);
}