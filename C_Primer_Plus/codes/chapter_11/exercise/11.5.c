// 自己动手写一个功能和strchr()函数相同的函数
#include <stdio.h>

const char *strchr_1(const char *st1, const char target);
int main(int argc, char *argv[])
{
    char source[40];
    char target = ' ';
    const char *position = NULL;

    puts("请输入一个字符串: ");
    fgets(source, 40, stdin);
    // 读取待搜索的字符
    while (target!=EOF) {
        printf("请输入一个待查找的字符: ");
        // 读取多余的换行符并将其丢弃
        while ((target = getchar())=='\n')
            continue;
        // 开始搜索
        if ((position = strchr_1(source, target)) != NULL)
            printf("在 %p 的地址上找到了 %c !\n", position, target);
        else
            printf("在你输入的字符串中未找到 %c, 再试一次吧!\n", target);
    }

    return 0;
}

const char *strchr_1(const char *st1, const char target)
{
    const char *target_p = NULL;
    while (*st1) {
        if (*st1 == target) {
            target_p = st1;
            break;
        }
        st1++;
    }

    return target_p;
}