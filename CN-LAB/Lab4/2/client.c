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
   int i, sockfd;
   char buf[100];
   struct sockaddr_in sa_addr;
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   sa_addr.sin_family = AF_INET;
   sa_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
   sa_addr.sin_port = htons(6001);
   memset(sa_addr.sin_zero, '\0', sizeof sa_addr.sin_zero);
   i = connect(sockfd, (struct sockaddr *)&sa_addr, sizeof(sa_addr));

   for (i = 0; i < 100; i++)
      buf[i] = '\0';
   recv(sockfd, buf, 100, 0);
   printf("%s\n", buf);

   close(sockfd);
}