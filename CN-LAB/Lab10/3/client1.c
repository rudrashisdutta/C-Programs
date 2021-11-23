#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#define MYPORT 6002
int main()
{
    int i, sockfd;
    char buf[100];
    struct sockaddr_in sa_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    sa_addr.sin_family = AF_INET;
    sa_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Loop back IP address
    sa_addr.sin_port = htons(MYPORT);
    memset(sa_addr.sin_zero, '\0', sizeof sa_addr.sin_zero);
    i = connect(sockfd, (struct sockaddr *)&sa_addr, sizeof(sa_addr));
    printf("Enter your full name\n");
    fgets(buf, 100, stdin);
    send(sockfd, buf, 100, 0);
    // recv(sockfd, buf, 100, 0);
    // int ctr = 0;
    // for (int i = 0; buf[i] != '\0'; i++)
    // {
    //     ctr++;
    //     // printf("%c",buf[i]);
    // }
    // ctr = ctr - 5;
    // for (int i = 0; i < ctr; i++)
    // {
    //     printf("%c", buf[i]);
    // }
    // printf("\n");
    close(sockfd);
}