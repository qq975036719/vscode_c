// 体验用malloc()函数创建动态数组
#include <stdio.h>
#include <stdlib.h>     // 包含malloc()和free()

int main(void)
{
    int max;
    double *ptd = NULL;
    int i;

    printf("请输入一个数组的元素个数: ");

    // 读入用户输入的数组元素个数
    if (scanf("%d", &max) != 1) {
        printf("输入数据错误 -- 程序已退出!");
        exit(EXIT_FAILURE);     // EXIT_FAILURE -- 表示程序异常终止 -- 作为exit()函数的参数使用
    }

    // 创建相应个数的数组
    ptd = (double *)malloc(max * sizeof(double));   // 利用malloc()函数动态分配数组空间
    if (ptd == NULL) {
        puts("内存分配失败 -- 程序已退出!");
        exit(EXIT_FAILURE);
    }

    // 提示用户输入数据到数组中
    printf("请输入%d个数据(浮点型), 输入q退出程序: ", max);

    // 将用户输入的数据添加到数组中
    for (int i = 0; i < max; i++)
        scanf("%lf", &ptd[i]);
    
    // 打印用户输入的数据
    puts("你输入的数据如下: ");
    for (i = 0; i < max; i++) {
        printf("%g ", ptd[i]);
        if (i % 7 == 6)
            putchar('\n');
    }
    if (i % 7 != 6)
        putchar('\n');
    puts("程序已结束");
    
    // 释放malloc()分配的变量
    free(ptd);

    return 0;
}