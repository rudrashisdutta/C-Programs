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
  int buffer[5];
  struct sockaddr_in servaddr = {0};
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd == -1)
  {
    perror("failed to create socket");
    exit(EXIT_FAILURE);
  }
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(12345);
  servaddr.sin_addr.s_addr = INADDR_ANY;
  int rc = bind(sockfd, (const struct sockaddr *)&servaddr,

                sizeof(servaddr));
  if (rc == -1)
  {
    perror("failed to bind");
    close(sockfd);
    exit(EXIT_FAILURE);
  }
  socklen_t len = 0;
  int i;
  int n = recvfrom(sockfd, buffer, 5 * sizeof(int),
                   MSG_WAITALL, 0, &len);
  printf("UNSORTED ARRAY\n");
  for (i = 0; i < 5; i++)
  {
    printf("%d\n", buffer[i]);
  }
  int c, d, t, j;
  for (c = 0; c < 5 - 1; c++)
  {
    for (d = 0; d < 5 - c - 1; d++)
    {
      if (buffer[d] > buffer[d + 1])
      {
        t = buffer[d];
        buffer[d] = buffer[d + 1];
        buffer[d + 1] = t;
      }
    }
  }
  printf("SORTED ARRAY\n");
  for (j = 0; j < 5; j++)
  {
    printf("%d\n", buffer[j]);
  }

  close(sockfd);

  return 0;
}
