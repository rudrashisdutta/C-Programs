#include <stdio.h> 
void swap(char *x, char *y) 
{
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
}
int permute(char *a, int l, int r,int count) 
{
    int i; 
    if (l == r)
    {
        count++;
        printf("%s\n", a);
        
    }
   else
   { 
        for (i = l; i <= r; i++)
        {
             
            swap((a+l), (a+i));
            count=permute(a, l+1, r,count);
            swap((a+l), (a+i)); 
        }
    }
    return count;
}
void main()
{
    int count,n=0;
    char str[100];
    printf("Enter the string:  ");
    scanf("%s",str); 
    for(int i=0;str[i]!='\0';i++)
    n++;
    count=permute(str, 0, n-1,0);
    printf("Count = %d",count);
} 
 
