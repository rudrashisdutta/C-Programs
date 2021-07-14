//SECTION Full Program
#include <stdio.h>
#include <stdlib.h>
//SECTION create Tree Full Code
//ANCHOR structure node
struct Node
{
     int num;
     struct Node *leftChild;
     struct Node *rightChild;
};
typedef struct Node *node;

//ANCHOR create and return a node
node createNode()
{
     node temp;
     temp = (node)malloc(sizeof(struct Node));
     return temp;
}

//ANCHOR create tree using reccursion
node createTree(node root)
{
     root = createNode();
     int num;
     printf("(enter -1 to store nothing)\t:");
     scanf("%d", &num);
     if (num != -1)
          root->num = num;
     else
          return NULL;
     printf("Enter the left child of %d:", root->num);
     root->leftChild = createTree(root->leftChild);
     printf("Enter the right child of %d:", root->num);
     root->rightChild = createTree(root->rightChild);
     return root;
}
//!SECTION create Tree Full Code

//SECTION TREE traveral functions

// ANCHOR postOrder function (traversal and printing of tree)
void printPostOrder(node root)
{
     if (root == NULL)
          return;
     printPostOrder(root->leftChild);
     printPostOrder(root->rightChild);
     printf("%d ", root->num);
}
//print postOrder (traversal and printing of tree)

// ANCHOR inOrder function (traversal and printing of tree)
void printInOrder(node root)
{
     if (root == NULL)
          return;
     printInOrder(root->leftChild);
     printf("%d ", root->num);
     printInOrder(root->rightChild);
}
//print inOrder (traversal and printing of tree)

// ANCHOR preOrder function (traversal and printing of tree)
void printPreOrder(node root)
{
     if (root == NULL)
          return;
     printf("%d ", root->num);
     printPreOrder(root->leftChild);
     printPreOrder(root->rightChild);
}
//print preOrder (traversal and printing of tree)
//!SECTION




void main()
{
     //create
     node root;
     printf("Enter the number you wish to store in root:");
     root = createTree(root);
     //create

     printf("Printing inOrder:\t");
     printInOrder(root); //print inOrder
     printf("Printing in preOrder:\t");
     printPreOrder(root); //print preOrder
     printf("Printing in postOrder:\t");
     printPostOrder(root); //print postOrder
     root = deleteNode(root,5);
     printf("Printing inOrder:\t");
     printInOrder(root); //print inOrder
}

/*
STUB
node newNode(int data){
     struct Node* node = (struct Node*) malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
     return(node);
}*/
//!SECTION Full Program