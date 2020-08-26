// 把两个数组对应元素相加后赋值给第三个数组
#include <stdio.h>

int main(void)
{
    // 数组声明
    int ar1[4] = {2, 4, 6, 8};
    int ar2[4] = {1, 0, 4, 6};
    int res[4];

    // 函数原型 -- 使用变长数组和const保证相加数组的安全性
    void get_res(int n, const int ar1[n], const int ar2[n], int res[n]);

    // 函数调用
    get_res(4, ar1, ar2, res);

    // 打印res数组查看结果
    for (int i = 0; i < 4; i++)
        printf("%d\t", res[i]);

    return 0;
}

void get_res(int n, const int ar1[n], const int ar2[n], int res[n])
{
    for (int i = 0; i < n; i++)
        res[i] = ar1[i] + ar2[i];
}