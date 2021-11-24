#include <stdio.h>
#include <sys/time.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/time.h>
#define STDIN 0
int main()
{
    char ch;
    fd_set readfd;
    FD_ZERO(&readfd);
    FD_SET(STDIN, &readfd);

    struct timeval tm;
    tm.tv_sec = 3;
    tm.tv_usec = 5000000;
    int ret = select(STDIN + 1, &readfd, 0, 0, &tm);
    if (ret == 0)
    {
        printf("Data not entered!\nTimeout occured!\n");
        return 0;
    }
    if (FD_ISSET(STDIN, &readfd))
    {
        scanf("%c", &ch);
        printf("Key value is %c\n", ch);
    }
    return 0;
}
