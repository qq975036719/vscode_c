// 导弹拦截
#include <stdio.h>
#include <string.h>

int max_num(int x, int y);
int main(void)
{
    int n;                    // n -- 导弹的数量
    int H[1000] = {0};        // 存储每个导弹的高度
    int D[1000];              // 表示导弹的编号

    
    while (scanf("%d", &n) == 1) {
        memset(D, 0, sizeof(D));
        for (int i = 1; i <= n; i++)
            scanf("%d", &H[i]);

        D[1] = 1;
        int maxx = 1;       // 最少需要的系统数量

        for (int i = 2; i <= n; i++) {
            D[i] = 1;
            for (int j = 1; j < i; j++) {
                if (H[i] > H[j]) {
                    D[i] = max_num(D[i], D[j] + 1);
                    maxx = max_num(maxx, D[i]);
                }
            }
        }

        printf("%d\n", maxx);
    }

    return 0;
}

int max_num(int x, int y)
{
    if (x>y)
        return x;
    else
        return y;
}