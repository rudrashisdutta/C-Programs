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
    int sockfd, fd1, length, i;
    char buf[100], buf1[100];
    struct sockaddr_in sa_addr, cl_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    sa_addr.sin_family = AF_INET;
    sa_addr.sin_addr.s_addr = INADDR_ANY;
    sa_addr.sin_port = htons(6000);
    memset(sa_addr.sin_zero, '\0', sizeof sa_addr.sin_zero);
    i = bind(sockfd, (struct sockaddr *)&sa_addr, sizeof(sa_addr));
    printf("%d%d\n", sockfd, i);
    if (i == -1)
    {
        printf("failed!");
        exit(0);
    }
    listen(sockfd, 5);
    length = sizeof(cl_addr);
    fd1 = accept(sockfd, (struct sockaddr *)&cl_addr, &length);
    recv(fd1, buf, 100, 0);
    int ctr;
    buf1[0] = buf[0];
    int j = 1;

    buf1[j] = '.';
    j++;
    for (int i = 1; buf[i] != '\0'; i++)
    {
        if (buf[i] == ' ')
        {
            buf1[j] = buf[i + 1];
            j++;
            buf1[j] = '.';
            ctr = i + 1;
            if (j == 3)
            {
                break;
            }
        }
    }
    j++;
    while (buf[ctr] != ' ')
    {
        ctr++;
    }
    for (int i = ctr + 1; buf[i] != '\0'; i++)
    {
        buf1[j] = buf[i];
        j++;
    }
    printf("%s", buf1);
    send(fd1, buf1, sizeof(buf1), 0);
    close(fd1);
}