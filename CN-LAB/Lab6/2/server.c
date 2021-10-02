#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
struct student
{
    int roll;
    char name[100];
    int marks;
} std[10];
int main()
{
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
    int sockfd, fd1, length, i;
    int buf = -1, marks;
    char name[100];
    struct sockaddr_in sa_addr, cl_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    sa_addr.sin_family = AF_INET;
    sa_addr.sin_addr.s_addr = INADDR_ANY;
    sa_addr.sin_port = htons(6007);
    memset(sa_addr.sin_zero, '\0', sizeof(sa_addr.sin_zero));
    i = bind(sockfd, (struct sockaddr *)&sa_addr, sizeof(sa_addr));
    printf("test %d%d\n", sockfd, i);
    listen(sockfd, 5);
    length = sizeof(cl_addr);
    fd1 = accept(sockfd, (struct sockaddr *)&cl_addr, &length);
    recv(fd1, &buf, sizeof(buf), 0);
    int flag = 0;
    for (int i = 0; i < 10; i++)
    {
        if (std[i].roll == buf)
        {
            buf = std[i].roll;
            strcpy(name, std[i].name);
            marks = std[i].marks;
            flag = 1;
        }
    }
    if (flag == 0)
    {
        buf = -1;
        send(fd1, &buf, sizeof(buf), 0);
    }
    else
    {
        send(fd1, &buf, sizeof(buf), 0);
        send(fd1, name, 100, 0);
        send(fd1, &marks, sizeof(int), 0);
    }
    close(fd1);
}