// 创建一个表格，用于打印一个数的平方和立方
#include <stdio.h>

int main(void)
{
    int start, end;
    // 读入信息
    printf("请输入开始的数字: ");
    scanf("%d", &start);
    printf("请输入结束的数字: ");
    scanf("%d", &end);

    // 打印表格标题信息
    printf("\t数字\t\t平方\t\t立方\n");

    int i; // 行数
    for (i = start; i <= end; i++) {
        printf("\t%d\t\t%d\t\t%d\n",i, i*i, i*i*i);
    }

    return 0;
}