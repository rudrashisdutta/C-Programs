#include<stdio.h>
#include<stdlib.h>
void multiply(int *a,int *b,int *res,int m,int n,int q){
    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
            for(int k=0;k<n;k++){
                *(res+i*q+j)+=(*(a+i*n+k)**(b+k*q+j));
            }
        }
    }
}
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
    int *a,*b,*res,m,n,p,q;
    printf("Enter the number of rows of the first matrix:\t");
    scanf("%d",&m);
    printf("Enter the number of columns of the first matrix:\t");
    scanf("%d",&n);
    printf("Enter the number of rows of the second matrix:\t");
    scanf("%d",&p);
    printf("Enter the number of columns of the second matrix:\t");
    scanf("%d",&q);
    if(n==p){
        printf("\n\nEnter the first matrix:\n");
        a=(int*)calloc(m*n,sizeof(int));
        enterMatrix(a,m,n);
        printf("\n\nEnter the second matrix:\n");
        b=(int*)calloc(p*q,sizeof(int));
        enterMatrix(b,p,q);
        res=(int*)calloc(m*q,sizeof(int));
        multiply(a,b,res,m,n,q);
        printf("\n\nMatrix 1:\n");
        printMatrix(a,m,n);
        printf("\n\nMatrix 2:\n");
        printMatrix(b,p,q);
        printf("\n\nMultiplied matrix:\n");
        printMatrix(res,m,q);
    }
    else{
        printf("Matrix multiplication is not possible!");
    }
}