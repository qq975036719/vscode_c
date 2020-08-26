// 二分查找猜数字
#include <stdio.h>
int main(void)
{
    int head = 1;
    int end = 100;
    int guess = (head + end) / 2;
    int count = 0;
    char ch;

    do {
        printf("你心里的数字是%d吗?\n", guess);
        count++;
        if (getchar() == 'y')
            break;      // 如果猜对了直接退出循环
        printf("那%d是比你心里的数字大还是小呢?(大了输入l/L, 小了输入s/S)\n",
               guess);

        while ((ch = getchar()) == '\n')    // 跳过回车换行符
            continue;               

        // 猜的数字比用户心里的数字大的情况
        if (ch == 'l' || ch == 'L') {
            end = guess - 1;
            guess = (head + end) / 2;
            continue;
        }
        // 猜的数字比用户心里的数字小的情况
        else if (ch == 's' || ch == 'S') {
            head = guess + 1;
            guess = (head + end) / 2;
            continue;
        }
        // 用户输入无效时的提示信息
        else {
            printf("请输入有效的选项l/L, s/S!\n");
            continue;
        }
    } while (getchar() != 'y');

    printf("我猜中啦,总共用了%d次猜中你心里的数字!", count);

    return 0;
}
