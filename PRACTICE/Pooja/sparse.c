#include<stdio.h>
#include<stdlib.h>
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
void printMatrix(int *a,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        printf("%d\t",*(a+i*n+j));
        printf("\n");
    }
}
void enterMatrix(int *a,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",(a+i*n+j));
        }
    }
}
void addTriplets(int *a,int *b,int *res){
    int m=1,n=1,o=1;
    for(int i=0;i<*(a+0);i++){
        for(int j=0;j<*(a+1);j++){
            
        }
    }
}
void main(){
    int *mat1,*mat2;
    int m,n;
    char ch='y';
    while (ch=='y'){
        printf("Number of rows:\t");
        scanf("%d",&m);
        printf("Number of columns:\t");
        scanf("%d",&n);
        mat1=(int*)calloc(m*n,sizeof(int));
        printf("Enter a sparse matrix:\n");
        enterMatrix(mat1,m,n);
        int *triplet1=(int*)calloc((m*n/2),sizeof(int));
        if(formTriplet(mat1,triplet1,m,n)==1){
            printf("The entered matrix is not a sparse matrix!\nEnter 'y' and click enter to re-enter the matrix or enter anything else to exit:\t");
            scanf("%*c");
            scanf("%c",&ch);
        }
        else{
            printf("Enter another sparse matrix:\n");
            enterMatrix(mat2,m,n);
            int *triplet2=(int*)calloc((m*n/2),sizeof(int));
            if(formTriplet(mat2,triplet2,m,n)==1){
                printf("The entered matrix is not a sparse matrix!\nEnter 'y' and click enter to re-enter the matrix or enter anything else to exit:\t");
                scanf("%*c");
                scanf("%c",&ch);
            }
            else{
                
            }
        }
    }
}