#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ctype.h>
#include <string.h>

#define PORT 8080
#define MAXLINE 1024

void main()
{
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
    if (bind(sockfd, (const struct sockaddr *)&servaddr,
             sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    char res[MAXLINE], input[MAXLINE];
    int len, ch;
    len = sizeof(cliaddr);
    while (1)
    {
        printf("Waiting for reply:\n");
        recvfrom(sockfd, &res, sizeof(res),
                 0, (struct sockaddr *)&servaddr,
                 &len);
        printf("Client : %s", res);
        if (strcmp(res, "exit\n") == 0)
        {
            strcpy(input, "exit");
            sendto(sockfd, &input, sizeof(input),
                   0, (const struct sockaddr *)&servaddr,
                   sizeof(servaddr));
            printf("Client exited the chat!'\n");
            break;
        }
        printf("\nEnter message to send:");
        fgets(input, MAXLINE, stdin);
        sendto(sockfd, &input, sizeof(input),
               0, (const struct sockaddr *)&servaddr,
               sizeof(servaddr));
        if (strcmp(input, "exit\n") == 0)
        {
            printf("You exited the chat!\n");
            break;
        }
    }
    close(sockfd);
}