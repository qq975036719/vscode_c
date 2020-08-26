// do while循环测试
#include <stdio.h>

int main(void)
{
    const int right_ans = 15;
    int num;
    do{
        printf("请输入一个数字: ");
        scanf("%d", &num);
    } while (num != right_ans);
    printf("恭喜你猜对啦，答案是%d!", right_ans);

    getchar();
    getchar();
    return 0;
}