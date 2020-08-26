#include <stdio.h>
#include <stdlib.h>

int max_num(int x, int y);
int v[1005], w[1005], dp[1005];
int main(void)
{
    int T, N, V, index;    // N -- 骨头数量  V -- 背包空间  index -- dp的下标

    scanf("%d", &T);
    
    while (T--) {
        scanf("%d %d", &N, &V);

        // 读入骨头的价值和体积
        for (int i = 0; i < N; i++)
            scanf("%d", &v[i]);
        for (int i = 0; i < N; i++)
            scanf("%d", &w[i]);

        // 边界
        for (index = 0; index <= V; index++)
            dp[index] = 0;

        for (int i = 0; i < N; i++)
            for (index = V; index >= w[i]; index--) {
                dp[index] = max_num(dp[index], dp[index - w[i]] + v[i]);
            }
        
        printf("%d\n", dp[V]);
    }
}

int max_num(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}