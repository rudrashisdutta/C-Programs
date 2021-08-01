//SECTION FULL PROGRAM
//NOTE Write a program to store a list of characters and print the list in the order of insertion using 2 stacks

#include<stdio.h>
#include<stdlib.h>
//ANCHOR struct of node
struct NODE{
    char c;
    struct NODE *next;
};
typedef struct NODE* node;
node createNode(){
    node temp;
    temp = (node) malloc(sizeof(struct NODE));
    temp->next = NULL;
    return temp;
}
//ANCHOR pushes a node in the stack
node push(node top,char data){
    node temp = createNode();
    temp->c = data;
    if(top == NULL){
        top = temp;
    }
    else{
        temp->next = top;
        top = temp;
    }
    return top;
}
//ANCHOR pops a node from the stack and stores its data using pointer for reusing purpose
node pop(node top1,char *c){
    if(top1!=NULL){
        node temp = top1;
        top1 = temp->next;
        *c = temp->c;
    }
    return top1;
}
void printStack(node top){
    node p = top;
    while(p!=NULL){
        printf("%c\t",p->c);
        p = p->next;
    }
}
void main(){
    node top1 = NULL , top2 = NULL;
    char c='y',data;
    while(c == 'y'){
        printf("Enter the data:\t");
        scanf("%s",&data);
        top1 = push(top1,data);
        printf("Do you want to push another data? Press y to enter:\t");
        scanf("%s",&c);
    }
    printf("\n\nStack:\t");
    printStack(top1);
    while(top1!=NULL){
        top1 = pop(top1,&data);
        top2 = push(top2,data);
    }
    printf("\n\nStack in the order of insertion:\t");
    printStack(top2);
}


//!SECTION FULL PROGRAM