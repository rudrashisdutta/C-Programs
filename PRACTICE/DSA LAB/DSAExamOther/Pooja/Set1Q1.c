//SECTION FULL PROGRAM
//NOTE Write a program to sort a circular linked list using Bubble sort.

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
typedef struct Node* node;
node head = NULL;
node tail = NULL;
void add(int data){
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->data = data;
    if(head == NULL){
        head = newNode;
        tail = newNode;
        newNode->next = head;
    }else {
        tail->next = newNode;
        tail = newNode;
    tail->next = head;
    }
}
void sortList() {
    node current = head, index = NULL;
    int temp;
    if(head == NULL) {
        printf("List is empty");
    }
    else {
        do{
            index = current->next;
            while(index != head) {
                if(current->data > index->data) {
                    temp =current->data;
                    current->data= index->data;
                    index->data = temp;
                }
                index= index->next;
            }
            current =current->next;
        }while(current->next != head);
    }
}
void display(){
    node current = head;
    if(head == NULL){
        printf("List is empty");
    }
    else{
        do{
            printf("%d ", current->data);
            current = current->next;
        }while(current != head);
        printf("\n");
    }
}
int main(){
    add(70);
    add(20);
    add(50);
    add(90);
    printf("Original list: \n");
    display();
    sortList();
    printf("Sorted list: \n");
    display();
}

//!SECTION FULL PROGRAM