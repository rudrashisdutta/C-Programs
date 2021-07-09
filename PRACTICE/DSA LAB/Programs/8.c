//SECTION FULL PROGRAM
//NOTE Write a program to show the use of realloac ()

#include<stdio.h>
#include<stdlib.h>
void enterArray(int *a,int m,int n){
    for(int i=m;i<m+n;i++){
        scanf("%d",(a+i));
    }
}
void print(int *a,int m){
    for(int i=0;i<m;i++){
        printf("%d\t",*(a+i));
    }
}
void main(){
    int m;
    printf("Enter the size of the array:\t");
    scanf("%d",&m);
    printf("Enter the array:\n");
    int *a;
    a=(int*)malloc(m*sizeof(int));
    enterArray(a,0,m);
    print(a,m);
    int n;
    printf("\n\nEnter the number of elements you wish to add in the array:\t");
    scanf("%d",&n);
    a=(int*)realloc(a,n*sizeof(int));
    enterArray(a,m,n);
    print(a,m+n);
}

//!SECTION FULL PROGRAM