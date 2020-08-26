// 使用循环处理数组
#include <stdio.h>

int main(void)
{
    const int SIZE = 10;
    int sum = 0;
    int index, score[SIZE];
    float average;
    printf("输入十个分数,本程序会计算总分和平均分: \n");

    for (index = 0; index < SIZE; index++)
        scanf("%d", &score[index]);
    // 检验输入是否成功
    printf("你输入的分数如下:\n\t");
        for (index = 0; index < SIZE; index++)
            printf("%d ", score[index]);
    // 计算总分
    for (index = 0; index < SIZE; index++)
        sum += score[index];
    // 计算平均分
    average = (float)sum / SIZE;
    // 打印总分和平均分
    printf("\n总分: %d, 平均分: %.2f", sum, average);

    return 0;
}