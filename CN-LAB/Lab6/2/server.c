#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
struct student
{
    int roll;
    char name[100];
    int marks;
};
#define MYPORT 4952
#define MAXBUFLEN 200
int main()
{
    struct student std[5];
    std[0].roll = 1906354;
    strcpy(std[0].name, "Rudrashis Kumar Dutta");
    std[0].marks = 90;

    std[1].roll = 1905330;
    strcpy(std[1].name, "Pooja Agarwal");
    std[1].marks = 95;

    std[2].roll = 192909;
    strcpy(std[2].name, "Shivangi Das");
    std[2].marks = 96;

    std[3].roll = 1906064;
    strcpy(std[3].name, "Sneha");
    std[3].marks = 92;

    std[4].roll = 1929339;
    strcpy(std[4].name, "Nikita Jain");
    std[4].marks = 93;

    int check = 0, index, roll = -1;
    int sockfd;
    struct sockaddr_in my_addr;
    struct sockaddr_in their_addr;
    socklen_t addr_len;
    int numbytes1, numbytes2, numbytes3, numbytes4, numbytes5;
    int buf;
    char name[100], add[100];
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        exit(1);
    }
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(MYPORT);
    my_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    int x;
    memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);
    if ((x = bind(sockfd, (struct sockaddr *)&my_addr, sizeof my_addr)) == -1)
    {
        perror("bind");
        exit(1);
    }
    printf("SERVER ONLINE .... %d%d\n", sockfd, x);
    listen(sockfd, 5);
    int length = sizeof(their_addr);
    int fd1 = accept(sockfd, (struct sockaddr *)&their_addr, &length);


    addr_len = sizeof their_addr;
    if ((numbytes5 = recvfrom(sockfd, &buf, sizeof(buf), 0,
                              (struct sockaddr *)&their_addr, &addr_len)) == -1)
    {
        perror("recvfrom");
        exit(1);
    }
    for (int i = 0; i < 5; i++)
    {
        if (buf == std[i].roll)
        {
            check = 1;
            index = i;
            break;
        }
    }
    if (check == 0)
    {
        if ((numbytes1 = sendto(sockfd, &roll, sizeof(roll), 0,
                                (struct sockaddr *)&their_addr, sizeof their_addr)) == -1)
        {
            perror("sendto");
            exit(1);
        }
    }
    if (check == 1)
    {
        if ((numbytes2 = sendto(sockfd, &std[index].roll, sizeof(std[index].roll), 0,
                                (struct sockaddr *)&their_addr, sizeof their_addr)) == -1)
        {
            perror("sendto");
            exit(1);
        }
        strcpy(name, std[index].name);
        if ((numbytes3 = sendto(sockfd, name, strlen(name), 0,
                                (struct sockaddr *)&their_addr, sizeof their_addr)) == -1)
        {
            perror("sendto");
            exit(1);
        }
        if ((numbytes4 = sendto(sockfd, &std[index].marks, sizeof(std[index].marks), 0,
                                (struct sockaddr *)&their_addr, sizeof their_addr)) == -1)
        {
            perror("sendto");
            exit(1);
        }
    }

    return 0;
}