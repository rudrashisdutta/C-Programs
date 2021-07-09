#include<stdio.h>
int insert(int array[500],int size,int pos,int element){
    if(pos-1>size||pos<1||size==500){
        printf("Position is out of scope.");
    }
    else{
            for(int i=size;i>pos-1;i--){
            array[i]=array[i-1];
        }
        size++;
        array[pos-1]=element;
        printf("The updated array is:\n");
        for(int i=0;i<size;i++)
            printf("%d\t",array[i]);
    }
    return size;
}
void main(){
    int size,array[500];
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
    printf("\n\nType 'y' and press enter to insert an element:\t");
    scanf("%*c");
    scanf("%c",&condition);
    while(condition=='y'&&size<500){
        printf("Enter the position of the array, you wish to insert in:\t");
        scanf("%d",&pos);
        printf("Enter the element you wish to insert in position %d:\t",pos);
        scanf("%d",&element);
        size=insert(array,size,pos,element);
        printf("\n\nType 'y' and press enter to insert an element:\t");
        scanf("%*c");
        scanf("%c",&condition);
    }
    if(size==500){
        printf("The Array is full!");
    }
}