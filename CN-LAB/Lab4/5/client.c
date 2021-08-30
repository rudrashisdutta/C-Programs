#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#define SERVERPORT 4952
int main()
{
    int sockfd;
    struct sockaddr_in their_addr;

    int pin, age;
    char add[100], name[100];
    long long mob;

    int numbytes, roll;
    int numbytes1, numbytes2, numbytes3, numbytes4, numbytes5, numbytes6, numbytes7, numbytes8;
    char arg[30];
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("socket");
        exit(1);
    }
    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(SERVERPORT);
    their_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("Enter a message\n");
    scanf("%d", &roll);

    if ((numbytes = sendto(sockfd, &roll, sizeof(roll), 0,
                           (struct sockaddr *)&their_addr, sizeof their_addr)) == -1)
    {
        perror("sendto");
        exit(1);
    }

    int addr_len = sizeof their_addr;

    if ((numbytes1 = recvfrom(sockfd, &roll, sizeof(roll), 0,
                              (struct sockaddr *)&their_addr, &addr_len)) == -1)
    {
        perror("recvfrom");
        exit(1);
    }
    if (roll == -1)
    {
        printf("Roll number not found\n");
    }
    else
    {

        if ((numbytes2 = recvfrom(sockfd, name, sizeof(name), 0,
                                  (struct sockaddr *)&their_addr, &addr_len)) == -1)
        {
            perror("recvfrom");
            exit(1);
        }

        if ((numbytes3 = recvfrom(sockfd, add, sizeof(add), 0,
                                  (struct sockaddr *)&their_addr, &addr_len)) == -1)
        {
            perror("recvfrom");
            exit(1);
        }

        if ((numbytes4 = recvfrom(sockfd, &mob, sizeof(mob), 0,
                                  (struct sockaddr *)&their_addr, &addr_len)) == -1)
        {
            perror("recvfrom");
            exit(1);
        }

        if ((numbytes5 = recvfrom(sockfd, &age, sizeof(age), 0,
                                  (struct sockaddr *)&their_addr, &addr_len)) == -1)
        {
            perror("recvfrom");
            exit(1);
        }

        if ((numbytes6 = recvfrom(sockfd, &pin, sizeof(pin), 0,
                                  (struct sockaddr *)&their_addr, &addr_len)) == -1)
        {
            perror("recvfrom");
            exit(1);
        }
    }
    if (roll != -1)
    {
        name[numbytes2] = '\0';
        add[numbytes3] = '\0';
        printf("Roll number is: %d\n", roll);
        printf("Name is: %s\n", name);
        printf("Adress is: %s\n", add);
        printf("Mobile number is: %lli\n", mob);
        printf("Pincode is: %d\n", pin);
    }
    close(sockfd);
    return 0;
}