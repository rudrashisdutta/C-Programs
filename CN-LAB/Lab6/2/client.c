#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
int main()
{
    int i, sockfd, roll, marks;
    char buf[100];
    struct sockaddr_in sa_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    sa_addr.sin_family = AF_INET;
    sa_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa_addr.sin_port = htons(6007);
    memset(sa_addr.sin_zero, '\0', sizeof sa_addr.sin_zero);
    i = connect(sockfd, (struct sockaddr *)&sa_addr, sizeof(sa_addr));
    printf("Enter the roll number to search\n");
    scanf("%d", &roll);
    send(sockfd, &roll, sizeof(roll), 0);
    roll = 0;
    recv(sockfd, &roll, sizeof(roll), 0);
    recv(sockfd, buf, 100, 0);
    recv(sockfd, &marks, sizeof(int), 0);
    if (roll == -1)
    {
        printf("Roll not found\n");
    }
    else
    {
        printf("Roll number of student is: %d\n", roll);
        printf("Name of student is: %s\n", buf);
        printf("Marks of student is: %d\n", marks);
    }
    close(sockfd);
    return 0;
}