#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, f[1001];
    scanf("%d", &n);

    f[0] = 0;
    for (int i=1; i<=n; i++)
    {
        f[i] = f[i&(i-1)] + 1;
    }

    for (int i=1; i<=n; i++)
    {
        printf("%d ", f[i]);
        if (i%10==0) printf("\n");
    }
    return 0;
}
