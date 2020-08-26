#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[1001], i, num, n;
    
    for (i=0; i<=1000; i++) a[i] = 0; // 初始化数组中的每个数的值为0
    
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        scanf("%d", &num);
        a[num]++;
    }
    
    for (i=0; i<=1000; i++)
        for (int j=1; j<=a[i]; j++)
            printf("%d ", i);
    
    return 0;
}
