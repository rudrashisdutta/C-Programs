#include <stdio.h>

long inf = 1e9;

void printParenthesis(int i, int j, int n, int *bracket, char *name) {
    if (i == j)
    {
        printf("%c", (*name)++);
        return;
    }
    printf("(");
    printParenthesis(i, *((bracket + i * n) + j), n,
                     bracket, name);

    printParenthesis(*((bracket + i * n) + j) + 1, j, n,
                     bracket, name);
    printf(")");
}

void matrixChainOrder(int p[], int n) {
    int m[n][n];
    int bracket[n][n];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = inf;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    char name = 'A';

    printf("Optimal Parenthesization is : ");
    printParenthesis(1, n - 1, n, (int *)bracket, &name);
    printf("\nOptimal Cost is : %d", m[1][n - 1]);
}

void main() {
    int arr[] = {2, 2, 4, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    matrixChainOrder(arr, n);
}