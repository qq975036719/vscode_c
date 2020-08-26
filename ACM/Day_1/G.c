// 01背包问题
#include <stdio.h>
#include <stdlib.h>

int max_num(int x, int y);
int main(void)
{
    int T, N, V;
    int v[1000] = {0};    // 每根骨头的价值
    int w[1000] = {0};    // 每根骨头的体积
    int v1, v2;     // 两种情况下的价值
    int *dp = NULL;       // 背包

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d", &N, &V);     // 读入骨头数量和背包空间

        // 初始化dp背包
        dp = (int *)malloc(sizeof(int ) * N * V);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < V; j++)
                dp[i * N + j] = 0;

        // 读入骨头的价值和体积
        for (int i = 1; i <= N; i++)
            scanf("%d", &v[i]);
        for (int i = 1; i <= N; i++)
            scanf("%d", &w[i]);

        // 开始处理dp背包
        for (int i = 1; i <= N; i++) {   // 前i根骨头
            for (int j = 0; j <= V; j++) {   // 背包的剩余体积
                if ((j-w[i]) < 0) {   // 第i件物品的体积大于背包剩余体积
                    dp[i*N+j] = dp[(i - 1)*N+j];    // 放入前一根骨头
                }
                else {
                    v1 = dp[(i - 1)*N+(j - w[i])] + v[i];    // 第i件物品能放进背包 -- 背包空间要减少w[i]
                    v2 = dp[(i - 1) * N + j];                // 第i件物品不能放进背包 -- 背包空间不变
                    dp[i*N+j] = max_num(v1, v2);
                    // printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
                }
            }
        }
        printf("%d", dp[N*N+V]);
        free(dp);
    }
    return 0;
}

int max_num(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}