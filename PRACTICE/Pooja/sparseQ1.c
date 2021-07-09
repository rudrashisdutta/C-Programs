#include<stdio.h>
#include<stdlib.h>
void printMatrix(int *a,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        printf("%d\t",*(a+i*n+j));
        printf("\n");
    }
}
int formTriplet(int* a,int* trip,int m,int n){
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(*(a+i*n+j)!=0)
            count++;
        }
    }
    if(count>=(m*n/2)) return 1;
    else{
        *(trip+0)=m;
        *(trip+1)=n;
        *(trip+2)=count;
        int k=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(*(a+i*n+j)!=0){
                    *(trip+k*3)=i;
                    *(trip+k*3+1)=j;
                    *(trip+k*3+2)=*(a+i*n+j);
                    k++;
                }
            }
        }
        return 0;
    }
}
void enterMatrix(int *a,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",(a+i*n+j));
        }
    }
}
void main(){
    int *mat;
    int m,n;
    char ch='y';
    while (ch=='y'){
        printf("Number of rows:\t");
        scanf("%d",&m);
        printf("Number of columns:\t");
        scanf("%d",&n);
        mat=(int*)calloc(m*n,sizeof(int));
        printf("Enter the sparse matrix:\n");
        enterMatrix(mat,m,n);
        int *triplet=(int*)calloc((m*n/2),sizeof(int));
        if(formTriplet(mat,triplet,m,n)==1){
            printf("The entered matrix is not a sparse matrix!\nEnter 'y' and click enter to re-enter the matrix or enter anything else to exit:\t");
            scanf("%*c");
            scanf("%c",&ch);
        }
        else{
            printf("The sparse matrix in triplet form is given as follows:\n");
            printMatrix(triplet,*(triplet+2)+1,3);
            break;
        }
    }
}