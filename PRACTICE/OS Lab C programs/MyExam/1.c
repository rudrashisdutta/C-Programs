#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node* node;
node head, tail = NULL;
void addNode(int data)
{
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}
void sortList()
{
    node current = head, index = NULL;
    int temp;
    if (head == NULL)
    {
        return;
    }
    else
    {
        while (current != NULL)
        {
            index = current->next;
            while (index != NULL)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}
void display()
{
    node current = head;
    if (head == NULL)
    {
        printf("List is empty \n");
        return;
    }
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void main()
{
    addNode(9);
    addNode(7);
    addNode(2);
    addNode(5);
    addNode(4);
    printf("Original list: \n");
    display();
    sortList();
    printf("Sorted list: \n");
    display();
}