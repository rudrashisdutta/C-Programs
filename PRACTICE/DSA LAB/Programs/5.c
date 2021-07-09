//SECTION FULL PROGRAM
//NOTE Swap the values of two variable using call by value and test whether it is working or not

#include<stdio.h>
void swap(int a,int b){
    printf("\nBefore swapping, values inside the fucntion:\t%d and %d",a,b);
    int temp=a;
    a=b;
    b=temp;
    printf("\nAfter swapping, values inside the fucntion:\t%d and %d",a,b);
}
void main(){
    int a,b;
    printf("\nEnter the 2 numbers:\n");
    scanf("%d%d",&a,&b);
    printf("\nBefore swapping, values in the main function:\t%d and %d",a,b);
    swap(a,b);
    printf("\nAfter swapping, values in the main function:\t%d and %d",a,b);
}

//!SECTION FULL PROGRAM