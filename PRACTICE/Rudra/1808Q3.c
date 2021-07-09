#include<stdio.h>
#include<stdlib.h>
void enterArray(int *a,int m,int n){
    for(int i=m;i<n;i++){
        scanf("%d",(a+i));
    }
}
void printArray(int *a,int m){
    for(int i=0;i<m;i++)
    printf("%d\t",*(a+i));
}
void main(){
    int *a,m,n;
    printf("Size of array:\t");
    scanf("%d",&m);
    a=(int*)calloc(m,sizeof(int));
    printf("Enter the elements:\n");
    enterArray(a,0,m);
    printf("Array:\t");
    printArray(a,m);
    printf("\n\nEnter the number of elements you would like to append to the array:\t");
    scanf("%d",&n);
    a=(int*)realloc(a,(m+n)*sizeof(int));
    printf("\n\nEnter the elements:\n");
    enterArray(a,m,m+n);
    printf("Array after appending:\t");
    printArray(a,m+n);
}