#include <stdio.h>
typedef unsigned char BYTE;
void main()
{
    unsigned int value = 0x11223344; //4 Bytes value
    BYTE a, b;                       //to store byte by byte value
    a = ((value >> 16) & 0xFF);      //extract 2nd last byte
    b = ((value >> 24) & 0xFF);      //extract last byte
    printf("a= %02X\n", a);
    printf("b= %02X\n", b);
}