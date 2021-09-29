#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main()
{
char buf[5];
struct sockaddr_in servaddr = {0};
int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
if(sockfd == -1)
{
perror("failed to create socket");
exit(EXIT_FAILURE);
}
servaddr.sin_family = AF_INET;
servaddr.sin_port = htons(12345);
servaddr.sin_addr.s_addr = INADDR_ANY;
int rc = bind(sockfd, (const struct sockaddr
*)&servaddr,

sizeof(servaddr));
if(rc == -1)
{
perror("failed to bind");
close(sockfd);
exit(EXIT_FAILURE);
}
socklen_t len = 0;
int i;
char n = recvfrom(sockfd, buf, 5*sizeof(int),
MSG_WAITALL,0, &len);

for(i=0;i<5;i++)
{
if((buf[i]=='A')||(buf[i]=='E')||(buf[i]=='I')||(buf[i]=='O')||(buf[i]=='U'))
{
printf("%c is the vowel at pos %d\n",buf[i],i+1);
}
}
close(sockfd);

return 0;
}
