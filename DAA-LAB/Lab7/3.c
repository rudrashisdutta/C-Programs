#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

struct MinHNode
{
    char item_354;
    unsigned freq;
    struct MinHNode *left, *right;
};

struct MinHeap
{
    unsigned size;
    unsigned capacity;
    struct MinHNode **array;
};

struct MinHNode *newNode(char item_354, unsigned freq)
{
    struct MinHNode *temp = (struct MinHNode *)malloc(sizeof(struct MinHNode));

    temp->left = temp->right = NULL;
    temp->item_354 = item_354;
    temp->freq = freq;

    return temp;
}

struct MinHeap *createMinH(unsigned capacity)
{
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHNode **)malloc(minHeap->capacity * sizeof(struct MinHNode *));
    return minHeap;
}

void swapMinHNode(struct MinHNode **a, struct MinHNode **b)
{
    struct MinHNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx)
    {
        swapMinHNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int checkSizeOne(struct MinHeap *minHeap)
{
    return (minHeap->size == 1);
}

struct MinHNode *extractMin(struct MinHeap *minHeap)
{
    struct MinHNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap *minHeap, struct MinHNode *minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}
void buildMinHeap(struct MinHeap *minHeap)
{
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

int isLeaf(struct MinHNode *root)
{
    return !(root->left) && !(root->right);
}

struct MinHeap *createAndBuildMinHeap(char item_354[], int freq[], int size)
{
    struct MinHeap *minHeap = createMinH(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(item_354[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

struct MinHNode *buildHuffmanTree(char item_354[], int freq[], int size)
{
    struct MinHNode *left, *right, *top;
    struct MinHeap *minHeap = createAndBuildMinHeap(item_354, freq, size);

    while (!checkSizeOne(minHeap))
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d\t", arr[i]);
    printf("\n");
}
void printHCodes(struct MinHNode *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printHCodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printHCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root))
    {
        printf("  %c   | ", root->item_354);
        printArray(arr, top);
    }
}

void printpreorder(struct MinHNode *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printpreorder(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printpreorder(root->right, arr, top + 1);
    }
    if (isLeaf(root))
    {
        printf("  %c   | ", root->item_354);
    }
}

void HuffmanCodes(char item_354[], int freq[], int size)
{
    struct MinHNode *root = buildHuffmanTree(item_354, freq, size);

    int arr[MAX], top = 0;

    printHCodes(root, arr, top);
}
void preorder(char item_354[], int freq[], int size)
{
    struct MinHNode *root = buildHuffmanTree(item_354, freq, size);

    int arr[MAX], top = 0;

    printpreorder(root, arr, top);
}

void main()
{
    int n, choice;
    printf("enter the no of characters: ");
    scanf("%d", &n);
    char arr[n];
    int freq[n];

    int size = sizeof(arr) / sizeof(arr[0]);
    while (1)
    {
        printf("\n0.Exit\n1.Input n unique characters with their frequencies into an array\n2.Display the Array\n3.Generate Huffman Tree and Traverse the tree with pre-order.\n4.Generate Huffman Codes for n charachers and display the same\n");
        printf("\nYour choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("\n\nQuitting...\n");
            return;
        case 1:
            printf("Enter the characters:  ");
            scanf("%s", arr);
            printf("Enter the frequencies:  ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &freq[i]);
            }
            break;
        case 2:
            printf("The array:\t");
            for (int i = 0; i < n; i++)
            {
                printf("%d\t", freq[i]);
            }
            break;
        case 3:
            printf(" Char");
            printf("\n------\n");
            preorder(arr, freq, n);
            break;
        case 4:
            printf(" Char | Huffman code ");
            printf("\n--------------------\n");
            HuffmanCodes(arr, freq, n);
            break;
        default:
            printf("\nWrong choice entered!");
        }
    }
}