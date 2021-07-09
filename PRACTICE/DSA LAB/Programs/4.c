//SECTION FULL PROGRAM
//NOTE Programs for today's lab is Matrix multiplication

#include<stdio.h>
void printMatrix(int a[100][100],int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void enterMatrix(int a[10][10],int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
}
void main(){
    int a[10][10],b[10][10];
    int m,n,p,q;
    printf("Enter the rows and columns of the first matrix:\n");
    scanf("%d%d",&m,&n);
    printf("Enter the rows and columns of the second matrix:\n");
    scanf("%d%d",&p,&q);
    printf("Enter the first matrix:\n");
    enterMatrix(a,m,n);
    printf("Enter the second matrix:\n");
    enterMatrix(b,p,q);
    int c[100][100];
    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
            c[i][j]=0;
            for(int k=0;k<n;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    printf("Resultant:\n");
    printMatrix(c,m,q);
}

//!SECTION FULL PROGRAM