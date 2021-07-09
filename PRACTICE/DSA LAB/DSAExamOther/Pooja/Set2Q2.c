//SECTION FULL PROGRAM
//NOTE Write a program to print a user entered list in reverse order using double linked list

#include<stdio.h>
#include<stdlib.h>
struct NODE{
    int number;
    struct NODE* next;
    struct NODE* prev;
};
typedef struct NODE* node;
node head,last;
node createNode(){
    node temp;
    temp = (node) malloc(sizeof(struct NODE));
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void nextNode(int data){
    node temp = createNode();
    temp->number = data;
    if(head == NULL){
        head = temp;
        last = temp;
    }
    else{
        node p = head;
        while(p->next!=NULL){
            p=p->next;
        }
        temp->prev = p;
        p->next = temp;
        last = temp;
    }
}
void printDLLRev(){
    node p = last;
    while(p!=NULL){
        printf("%d\t",p->number);
        p = p->prev;
    }
}
void main(){
    char c='y';
    int data;
    while(c == 'y'){
        printf("Enter the data:\t");
        scanf("%d",&data);
        nextNode(data);
        printf("Do you want to enter another data? Press y to enter:\t");
        scanf("%s",&c);
    }
    printf("Entered data in reverse order:\t");
    printDLLRev();
}


//!SECTION FULL PROGRAM