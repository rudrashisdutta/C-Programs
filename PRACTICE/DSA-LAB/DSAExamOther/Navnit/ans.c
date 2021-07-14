//SECTION FULL PROGRAM
//NOTE
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int getMin(int arr[], int n);
int getMax(int arr[], int n);


bool areConsecutive(int arr[], int n)
{
    if ( n <  1 )
    return false;
    int min = getMin(arr, n);
    int max = getMax(arr, n);
    if (max - min  + 1 == n)
    {
        bool *visited = (bool *) calloc (n, sizeof(bool));
        int i;
        for (i = 0; i < n; i++)
        {
            if ( visited[arr[i] - min] != false )
            return false;
            visited[arr[i] - min] = true;
        }
        return true;
    }
    return false;
}


int getMin(int arr[], int n)
{
  int min = arr[0];
  for (int i = 1; i < n; i++)
   if (arr[i] < min)
     min = arr[i];
  return min;
}
int getMax(int arr[], int n)
{
  int max = arr[0];
  for (int i = 1; i < n; i++)
   if (arr[i] > max)
     max = arr[i];
  return max;
}

int maxIndexDiff(int arr[], int n)
{
    int maxDiff = -1;
    int i, j;
 
    for (i = 0; i < n; ++i) {
        for (j = n - 1; j > i; --j) {
            if (arr[j] > arr[i] && maxDiff < (j - i))
                maxDiff = j - i;
        }
    }
 
    return maxDiff;
}

int main()
{   int n;
    printf("Enter size  :   ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    if(areConsecutive(arr, n) == true)
        printf("Array elements are consecutive.");
    else
        printf("Array elements are not consecutive.");
    
    int size = sizeof(arr) / sizeof(arr[0]);
    int maxDiff = maxIndexDiff(arr, size);
    printf("\nMax Diff:%d", maxDiff);
    getchar();
    return 0;
}


//!SECTION FULL PROGRAM