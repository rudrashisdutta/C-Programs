#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maximum(int x, int y) {
    if (x > y)
        return x;
    else
        return y;
}
void lcs(char *X, char *Y, int m, int n) {
    int L[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = maximum(L[i - 1][j], L[i][j - 1]);
        }
    }
    int index = L[m][n];
    printf("length of lcs is %d\n", index);
    char lcs[index + 1];
    lcs[index] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
    printf("%s", lcs);
}
void main() {
    char X[] = "10010101";
    char Y[] = "010110110";
    int m = strlen(X);
    int n = strlen(Y);
    lcs(X, Y, m, n);
}