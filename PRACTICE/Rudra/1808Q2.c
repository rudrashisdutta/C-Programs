#include<stdio.h>
#include<stdlib.h>
void enterMatrix(int *a,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",(a+i*n+j));
        }
    }
}
void printMatrix(int *a,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        printf("%d\t",*(a+i*n+j));
        printf("\n");
    }
}
void main(){
    int *a,m,n;
    printf("Number of rows:\t");
    scanf("%d",&m);
    printf("Number of columns:\t");
    scanf("%d",&n);
    printf("Enter the matrix:\n");
    a=(int*)calloc(m*n,sizeof(int));
    enterMatrix(a,m,n);
    printf("Matrix entered is:\n");
    printMatrix(a,m,n);
}