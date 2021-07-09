#include <stdio.h> 
#include <string.h> 
int swap(char *x, char *y,int count) 
{ 
    count++;
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
    return count;
}
int permute(char *a, int l, int r,int count) 
{
    int i; 
    if (l == r)
    {
        printf("%s\n", a);
        
    }
   else
   { 
        for (i = l; i <= r; i++) 
        {
             
            count=swap((a+l), (a+i),count);
            count=permute(a, l+1, r,count);
            count=swap((a+l), (a+i),count); 
        } 
    } 
    return count;
}
void main()
{
    int count;
    char str[100];
    printf("Enter the string:  ");
    scanf("%s",str); 
    int n = strlen(str); 
    count=permute(str, 0, n-1,0);
    printf("Count = %d",count);
} 
 
