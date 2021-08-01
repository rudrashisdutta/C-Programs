#include <stdio.h>
void main()
{
    unsigned int i = 1;
    char *c = (char *)&i;
    if (*c)
    {
        printf("Little endian");
    }
    else
    {
        printf("Big endian");
    }
}