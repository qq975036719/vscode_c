#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 5;
    int m = 6;
    int **p = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        p[i] = (int *)malloc(sizeof(int) * m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            p[i][j] = 0;
        }
    }
    printf("%d", p[0][2]);
}