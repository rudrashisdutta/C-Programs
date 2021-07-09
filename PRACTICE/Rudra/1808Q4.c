#include<stdio.h>
void enterArray(int a[50],int n){
    for(int i=0;i<n;i++){
        scanf("%d",(a+i));
    }
}
void printArray(int a[50],int m){
    for(int i=0;i<m;i++)
    printf("a[%d]= %d\n",i,*(a+i));
}
void main(){
    int a[50],m;
    printf("Size of array:\t");
    scanf("%d",&m);
    printf("Enter the elements:\n");
    enterArray(a,m);
    printf("Array:\n");
    printArray(a,m);
}