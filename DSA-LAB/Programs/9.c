//SECTION FULL PROGRAM
//NOTE Write a program to access dynamically allocated memory as a 1D array(subscripting pointer variable).

#include<stdio.h>
#include<stdlib.h>
void main(){
    int *a;
    int n;
    printf("Enter the size of the array:\t");
    scanf("%d",&n);
    a = (int*)malloc(n*sizeof(int));
    printf("Enter the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Array is:\t");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}
//!SECTION FULL PROGRAM