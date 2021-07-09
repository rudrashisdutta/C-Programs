#include<stdio.h>
void printMatrixForm(int x[10][10],int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        printf("%d\t",x[i][j]);
        printf("\n");
    }
}
void main(){
    int a[10][10],b[10][10],c[10][10],m,n,p,q;
    printf("Enter the number of rows and columns of matix 1:\n");
    scanf("%d%d",&m,&n);
    printf("Enter the number of rows and columns of matix 2:\n");
    scanf("%d%d",&p,&q);
    if(n!=p){
        printf("Matrix multiplication is not possible!");
    }
    else{
        printf("Enter the elements of the first matrix:\n");
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
        }
        printf("Enter the elements of the second matrix:\n");
        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++)
            scanf("%d",&b[i][j]);
        }
        printf("First Matrix:\n");
        printMatrixForm(a,m,n);
        printf("Second Matrix:\n");
        printMatrixForm(b,p,q);
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){
                c[i][j]=0;
                for(int k=0;k<n;k++){
                    c[i][j]+=a[i][k]*b[k][j];
                }
            }
        }
        printf("The multiplied matrix is:\n");
        printMatrixForm(c,m,q);
    }
}