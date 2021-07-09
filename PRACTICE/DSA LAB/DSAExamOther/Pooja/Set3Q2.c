//SECTION FULL PROGRAM
//NOTE Write a program to store a list of numbers using stack and find the number of pop operations required to retrieve a given number

#include<stdio.h>
#include<stdlib.h>
//ANCHOR struct of node
struct NODE{
    int number;
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
node push(node top,int data){
    node temp = createNode();
    temp->number = data;
    if(top == NULL){
        top = temp;
    }
    else{
        temp->next = top;
        top = temp;
    }
    return top;
}

int findNumberOfPopOperationsRequired(node top,int data,int *numberOfPops){
    int returnVal = 0;
    if(data == top->number){
        (*numberOfPops)++;
        return 1;
    }
    else{
        if(top->next == NULL)
        return 0;
        returnVal = findNumberOfPopOperationsRequired(top->next,data,numberOfPops);
    }
    return returnVal;
}

void main(){
    node top = NULL;
    char c='y',data;
    while(c == 'y'){
        printf("Enter the data:\t");
        scanf("%d",&data);
        top = push(top,data);
        printf("Do you want to push another data? Press y to enter:\t");
        scanf("%s",&c);
    }
    
}


//!SECTION FULL PROGRAM