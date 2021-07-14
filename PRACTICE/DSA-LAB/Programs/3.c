//SECTION FULL PROGRAM
//NOTE Write a program that returns sum of squares of all odd numbers from 1 to 25.

#include<stdio.h>
int func(){
    int a=0;
    for(int i=1;i<=25;i+=2){
        a+=(i*i);
    }
    return a;
}
void main(){
    printf("Value:\t%d",func());
}

//!SECTION FULL PROGRAM