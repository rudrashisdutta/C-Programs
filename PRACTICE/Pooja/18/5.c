#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct books
{
    char title[100],author[100],publication[100];
    int price;
};
void main()
{
    int n;
    struct books *ptr;
    printf("Enter the number of books:  ");
    ptr=(struct books*) malloc(n*sizeof(struct books));
    for(int i=0;i<n;++i)
    {
        printf("Enter the details of book %d:\n\nTitle,Author,Publication,Price respectively  ",i+1);
        scanf("%*c");
        gets((ptr+i)->title);
        gets((ptr+i)->author);
        gets((ptr+i)->publication);
        scanf("%d",&(ptr+i)->price);
    }
    printf("\n\n\n\n");
    for(int i=0;i<n;++i)
    {
        printf("Title:  %s\nAuthor:  %s\nPublication:  %s\nPrice:  %d\n\n",(ptr+i)->title,(ptr+i)->author,(ptr+i)->publication,(ptr+i)->price);
    }
}