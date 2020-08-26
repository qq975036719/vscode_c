// 拼接两个字符串，检查第1个数组的大小
#include <stdio.h>
#include <string.h>
#define SIZE 30
#define BUGSIZE 13
char *s_gets(char *st, int n);

int main(void)
{
    char flower[SIZE];
    char addon[] = "s smell like old shoes.";
    char bug[BUGSIZE];
    int available;

    // 读入最喜欢的花
    puts("你最喜欢的花是什么?");
    s_gets(flower, SIZE);
    // 判断拼接后的字符串是否超出大小
    if ((strlen(flower) + strlen(addon) + 1) <= SIZE)
        strcat(flower, addon);
    puts(flower);
    // 读入最喜欢的bug
    puts("你最喜欢的bug是什么?");
    s_gets(bug, BUGSIZE);
    available = BUGSIZE - strlen(bug) - 1;
    strncat(bug, addon, available);
    puts(bug);

    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        // 遍历传入的字符串
        while (st[i] != '\0' && st[i] != '\n')
            i++;
        // 将换行符替换为空字符
        if (st[i] == '\n')
            st[i] = '\0';
        // 跳过剩余的输入
        else
            while (getchar()!='\n')
                continue;
    }
    return ret_val;
}