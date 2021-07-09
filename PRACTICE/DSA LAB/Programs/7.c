//SECTION FULL PROGRAM
//NOTE Write a program to dynamically allocate a 2D array using pointer to an array.

#include<stdio.h>
void enterMatrix(int *a,int n){
    for(int i=0;i<n;i++){
        scanf("%d",(a+i));
    }
}
void printMatrix(int a[10][10],int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void main(){
    int ab[10][10];
    int m,n;
    printf("Enter the rows and columns of the first matrix:\n");
    scanf("%d%d",&m,&n);
    printf("Enter the first matrix:\n");
    for(int i=0;i<m;i++){
        int *a=ab[i];
        enterMatrix(a,n);
    }
    printMatrix(ab,m,n);
}

//!SECTION FULL PROGRAM