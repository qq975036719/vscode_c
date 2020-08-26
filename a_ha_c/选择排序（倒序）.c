#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, j, t;
    
    scanf("%d", &n);
    int a[n];
    
    for (i=0; i<=n-1; i++) scanf("%d", &a[i]);  // 读入输入的数字
    
    for (i=0; i<=n-2; i++)                      // 选择对比的轮数
        for (j=i+1; j<=n-1; j++)                
            if (a[i] < a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
    
    for (i=0; i<=n-1; i++) printf("%d ", a[i]);
    return 0;
}
