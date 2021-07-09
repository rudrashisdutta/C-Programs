//SECTION Full Program
#include<stdio.h>
#include<stdlib.h>
//SECTION create Tree Full Code
//ANCHOR structure node
struct Node{
    int num;
    struct Node *leftChild;
    struct Node *rightChild;
};
typedef struct Node* node;

//ANCHOR create and return a node
node createNode(){
    node temp;
    temp = (node) malloc(sizeof(struct Node));
}

//ANCHOR create tree using reccursion
node createTree(node root){
    root = createNode();
    int num;
    printf("(enter -1 to store nothing)\t:");
    scanf("%d",&num);
    if(num!=-1) root->num=num;
    else return NULL;
    printf("Enter the left child of %d:",root->num);
    root->leftChild = createTree(root->leftChild);
    printf("Enter the right child of %d:",root->num);
    root->rightChild = createTree(root->rightChild);
    return root;
}
//!SECTION create Tree Full Code

void main(){
    node root;
    printf("Enter the number you wish to store in root:");
    root = createTree(root);
}
//!SECTION Full Program