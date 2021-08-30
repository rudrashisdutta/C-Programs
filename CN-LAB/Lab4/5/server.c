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
    int age;
    char add[100];
    int pin;
    long long mob;
};
#define MYPORT 4952
#define MAXBUFLEN 200
int main()
{
    struct student std[5];
    std[0].roll = 1906354;
    strcpy(std[0].name, "Rudrashis Kumar Dutta");
    std[0].age = 20;
    strcpy(std[0].add, "Cuttack");
    std[0].pin = 753001;
    std[0].mob = 9437577049;

    std[1].roll = 1905330;
    strcpy(std[1].name, "Pooja Agarwal");
    std[1].age = 19;
    strcpy(std[1].add, "Bhubaneswar");
    std[1].pin = 732221;
    std[1].mob = 7329182293;

    std[2].roll = 192909;
    strcpy(std[2].name, "Shivangi Das");
    std[2].age = 21;
    strcpy(std[2].add, "Cuttack");
    std[2].pin = 753002;
    std[2].mob = 9177255241;

    std[3].roll = 1906064;
    strcpy(std[3].name, "Sneha");
    std[3].age = 20;
    strcpy(std[3].add, "Patna");
    std[3].pin = 182665;
    std[3].mob = 2441672778;

    std[4].roll = 1929339;
    strcpy(std[4].name, "Nikita Jain");
    std[4].age = 20;
    strcpy(std[4].add, "Cuttack");
    std[4].pin = 753001;
    std[4].mob = 8897652534;
    int check = 0, index, roll = -1;
    int sockfd;
    struct sockaddr_in my_addr;
    struct sockaddr_in their_addr;
    socklen_t addr_len;
    int numbytes1, numbytes2, numbytes3, numbytes4, numbytes5, numbytes6, numbytes7, numbytes8;
    int buf;
    char name[100], add[100];
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("socket");
        exit(1);
    }
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(MYPORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof my_addr) == -1)
    {
        perror("bind");
        exit(1);
    }
    addr_len = sizeof their_addr;
    if ((numbytes7 = recvfrom(sockfd, &buf, sizeof(buf), 0,
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
        if ((numbytes4 = sendto(sockfd, &std[index].add, sizeof(std[index].add), 0,
                                (struct sockaddr *)&their_addr, sizeof their_addr)) == -1)
        {
            perror("sendto");
            exit(1);
        }

        if ((numbytes5 = sendto(sockfd, &std[index].mob, sizeof(std[index].mob), 0,
                                (struct sockaddr *)&their_addr, sizeof their_addr)) == -1)
        {
            perror("sendto");
            exit(1);
        }

        if ((numbytes6 = sendto(sockfd, &std[index].age, sizeof(std[index].age), 0,
                                (struct sockaddr *)&their_addr, sizeof their_addr)) == -1)
        {
            perror("sendto");
            exit(1);
        }

        if ((numbytes8 = sendto(sockfd, &std[index].pin, sizeof(std[index].pin), 0,
                                (struct sockaddr *)&their_addr, sizeof their_addr)) == -1)
        {
            perror("sendto");
            exit(1);
        }
    }

    return 0;
}