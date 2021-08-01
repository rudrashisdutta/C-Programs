#include <stdio.h>

typedef unsigned char BYTE;

int main()
{
    unsigned int value = 0x11223344; //4 Bytes value

    BYTE a, b, c, d; //to store byte by byte value

    a = (value & 0xFF);        //extract first byte
    b = ((value >> 8) & 0xFF); //extract second byte

    printf("a= %02X\n", a);
    printf("b= %02X\n", b);
    return 0;
}