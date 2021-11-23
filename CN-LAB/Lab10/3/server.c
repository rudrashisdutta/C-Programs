#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#define MYPORT1 6002
#define MYPORT2 6003
int main()
{
    int sockfd, sockfd1, fd1, fd2, length, length1, i, j;
    char buf[100];
    struct sockaddr_in sa_addr, cl_addr, sa_addr1, cl_addr1;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    sockfd1 = socket(AF_INET, SOCK_STREAM, 0);
    sa_addr.sin_family = AF_INET;
    sa_addr.sin_addr.s_addr = INADDR_ANY;
    sa_addr.sin_port = htons(MYPORT1);
    sa_addr1.sin_family = AF_INET;
    sa_addr1.sin_addr.s_addr = INADDR_ANY;
    sa_addr1.sin_port = htons(MYPORT2);
    memset(sa_addr.sin_zero, '\0', sizeof sa_addr.sin_zero);
    memset(sa_addr1.sin_zero, '\0', sizeof sa_addr1.sin_zero);
    i = bind(sockfd, (struct sockaddr *)&sa_addr, sizeof(sa_addr));
    j = bind(sockfd1, (struct sockaddr *)&sa_addr1, sizeof(sa_addr1));
    printf("test %d%d\n", sockfd, i);
    printf("test %d%d\n", sockfd1, j);
    listen(sockfd, 5);
    listen(sockfd1, 5);
    length = sizeof(cl_addr);
    length1 = sizeof(cl_addr1);
    fd1 = accept(sockfd, (struct sockaddr *)&cl_addr, &length);
    fd2 = accept(sockfd1, (struct sockaddr *)&cl_addr1, &length1);

    recv(fd1, buf, 100, 0);
    send(fd2, buf, 100, 0);
    close(fd2);
    close(fd1);
}