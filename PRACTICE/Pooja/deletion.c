#include<stdio.h>
int delete(int array[5],int size,int pos){
    if(pos>size||pos<1||size==0){
        printf("Position is out of scope.");
    }
    else{
            for(int i=pos-1;i<size-1;i++){
            array[i]=array[i+1];
        }
        size--;
        printf("The updated array is:\n");
        for(int i=0;i<size;i++)
            printf("%d\t",array[i]);
    }
    return size;
}
void main(){
    int size,array[5];
    printf("Enter the number of elements of the array:\t");
    scanf("%d",&size);
    printf("Enter the elements of the array:\n");
    for(int i=0;i<size;++i)
        scanf("%d",&array[i]);
    printf("The entered array is:\n");
    for(int i=0;i<size;i++)
        printf("%d\t",array[i]);
    int pos,element;
    char condition='x';
    printf("\n\nType 'y' and press enter to delete an element:\t");
    scanf("%*c");
    scanf("%c",&condition);
    while(condition=='y'&&size>0){
        printf("Enter the position of the element in the array, you wish to delete:\t");
        scanf("%d",&pos);
        size=delete(array,size,pos);
        printf("\n\nType 'y' and press enter to delete an element:\t");
        scanf("%*c");
        scanf("%c",&condition);
    }
    if(size==0){
        printf("The Array is empty!");
    }
}