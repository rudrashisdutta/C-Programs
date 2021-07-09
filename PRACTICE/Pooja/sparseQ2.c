#include<stdio.h>
#include<stdlib.h>
int checkSparse(int* a,int m,int n,int *count){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(*(a+i*n+j)!=0)
            *(count)+=1;
        }
    }
    if(*(count)<(m*n)/2)
    return 1;
    else return 0;
}
void formTriplet(int* a,int* trip,int m,int n,int count){
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
void addMatrix(int *a,int *b,int *add,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        *(add+i*n+j)=*(a+i*n+j)+*(b+i*n+j);
    }
}
void main(){
    int *a,*b,m,n;
    char ch='y';
    while(ch=='y'){
        ch='y';
        int count=0;
        printf("Number of rows: \t");
        scanf("%d",&m);
        printf("Number of columns:\t");
        scanf("%d",&n);
        printf("\n\nEnter the first sparse array:\n");
        a=(int*)calloc(m*n,sizeof(int));
        enterMatrix(a,m,n);
        if(checkSparse(a,m,n,&count)==0){
            printf("The first matrix is not a sparse matrix!\nEnter 'y' and click enter to re-enter the matrix or enter anything else to exit:\t");
            scanf("%*c");
            scanf("%c",&ch);
        }
        else{
            while(ch=='y'){
                printf("\n\nEnter the second sparse array:\n");
                b=(int*)calloc(m*n,sizeof(int));
                enterMatrix(b,m,n);
                count=0;
                if(checkSparse(b,m,n,&count)==0){
                    printf("The second matrix is not a sparse matrix!\nEnter 'y' and click enter to re-enter the matrix or enter anything else to exit:\t");
                    scanf("%*c");
                    scanf("%c",&ch);
                }
                else{
                    int counter=0,*add,*triplet;
                    add=(int*)calloc(m*n,sizeof(int));
                    addMatrix(a,b,add,m,n);
                    if(checkSparse(add,m,n,&counter)==0){
                        printf("The resultant matrix is not a sparse matrix!\nEnter 'y' and click enter to re-enter the matrices or enter anything else to exit:\t");
                        scanf("%*c");
                        scanf("%c",&ch);
                        break;
                    }
                    else{
                        triplet=(int*)calloc(counter*3,sizeof(int));
                        formTriplet(add,triplet,m,n,counter);
                        printf("The triplet form of the resultant matrix:\n");
                        printMatrix(triplet,counter+1,3);
                        ch='n';
                        break;
                    }
                }
            }
        }
    }
}