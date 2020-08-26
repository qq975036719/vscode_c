#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, num[10000], temp[10000];
    scanf("%d%d", &n, &m);

    // 读入用户输入的n个数字
    for (int i=0; i<n; i++)
        scanf("%d", &num[i]);

    // 创建一个 1 ~ m 的数组
    for (int i=0; i<m; i++)
        temp[i] = i+1;

    // 让 1 ~ m 的数字分别判断是否能整除读入的n个数字
    for (int i=1; i<=m; i++)
    {
        for (int j=0; j<n; j++)
            {
             if (i%num[j]==0)
                temp[i-1] = 0;
            }
    }

    // 打印符合条件的值
    for (int i=0; i<m; i++)
    {
        if (temp[i] != 0) printf("%d ", temp[i]);
    }

    return 0;
}
