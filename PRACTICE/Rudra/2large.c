#include<stdio.h>
#include<stdlib.h>
void main()
{
    int m,temp;
    repeat1:
    printf("Enter the size of the array");
    scanf("%d",&m);
    if(m<2)
    {
        printf("\bERROR:\b1 element present!\nNo second element found!");
        int d;
        repeat2:
        printf("Do you want to try again?\nPress\n1-yes\n2-no\n");
        scanf("%d",&d);
        if(d==1)
        goto repeat1;
        else if(d==2)
        {
            printf("Ending....");
            exit(0);
        }
        else
        {
            printf("ERROR:Invalid entery!\n");
            goto repeat2;
        }
        
        
    }
    int a[m];
    printf("Enter the elements of the array.\n");
    for(int i=0;i<m;i++)
    scanf("%d",&a[i]);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<m-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("The second largest element is\t%d\n",a[m-2]);
    int ch;
    repeat3:
    printf("Do you want to try with another array?\n1-yes\n2-no\n");
    scanf("%d",&ch);
    if(ch==1)
    goto repeat1;
    else if(ch==2)
    {
        printf("Endind....");
        exit(0);
    }
    else
    {
        printf("ERROR:Invalid entry!\n");
        goto repeat3;
    }
}