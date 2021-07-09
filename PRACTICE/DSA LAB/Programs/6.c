//SECTION FULL PROGRAM
//NOTE Program to dynamically allocate a 2D array (pointer to pointer .. **)

#include<stdio.h>
#include<stdlib.h>
void printMatrix(int *a,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",*(a+(i*n)+j));
        }
        printf("\n");
    }
}
void enterMatrix(int *a,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",(a+(i*n)+j));
        }
    }
}
void main(){
    int *a;
    int m,n;
    printf("Enter the rows and columns of the first matrix:\n");
    scanf("%d%d",&m,&n);
    a=(int*)malloc(m*n*sizeof(int));
    printf("Enter the first matrix:\n");
    enterMatrix(a,m,n);
    printMatrix(a,m,n);
}

//!SECTION FULL PROGRAM