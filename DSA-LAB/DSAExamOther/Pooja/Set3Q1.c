//SECTION FULL PROGRAM
//NOTE Wrtie a program to implement binary search tree and find the depth of a NODE
#include <stdio.h>
#include <stdlib.h>
struct NODE {
    int key;
    struct NODE *left, *right;
};
typedef struct NODE* node;
//ANCHOR A utility function to create a new BST NODE
node newNODE(int item)
{
    node temp
        = (struct NODE*)malloc(sizeof(struct NODE));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

//ANCHOR A utility function to do inorder traversal of BST
void inorder(node root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

/*ANCHOR
 A utility function to insert 
   a new NODE with given key in 
 * BST */
node insert(node root, int key)
{
    /* If the tree is empty, return a new NODE */
    if (root == NULL)
        return newNODE(key);
    /* Otherwise, recur down the tree */
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    /* return the (unchanged) NODE pointer */
    return root;
}

//ANCHOR Searches a node in the BST then returns if found(1) or not(0) and also the depth using pointer
int search(node root,int key,int *depth){
    int returnVal=0;
    if(root!=NULL){
        if(key>root->key){
            if(root->right == NULL)
            return 0;
            (*depth)++;
            returnVal = search(root->right,key,depth);
        }
        else if(key<root->key){
            if(root->left == NULL)
            return 0;
            (*depth)++;
            returnVal = search(root->left,key,depth);
        }
        else{
            (*depth)++;
            returnVal = 1;
        }
    }
    else{
        return 0;
    }
    return returnVal;
}

//ANCHOR Driver Code
int main()
{
    node root = NULL;
    int data;
    char c = 'y';
    while(c == 'y'){
        printf("Enter a data:\t");
        scanf("%d",&data);
        root = insert(root,data);
        printf("Enter y to enter another data in the BST:\t");
        scanf("%s",&c);
    }
    //ANCHOR print iNODEr traversal of the BST
    inorder(root);
    int depth = 0;
    printf("\n\nEnter the data to search:\t");
    scanf("%d",&data);
    int returnVal = search(root,data,&depth);
    if(returnVal == 1){
        printf("\n\nDepth of the entered node is:\t%d",depth);
    }
    else{
        printf("\n\nEntered node is not found!");
    }
    return 0;
}


//!SECTION FULL PROGRAM