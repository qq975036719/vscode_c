//使用逻辑运算符
#include <stdio.h>
#define PERIOD '.'

int main(void)
{
    char ch;
    int charcount = 0;
    printf("此程序会统计这句话中的单引号和双引号以外的字符数量\n");
    printf("请输入一句话,以'.'结尾: ");

    while ((ch = getchar()) != PERIOD) {
        if (ch != '"' && ch != '\'')
            charcount++;
    }
    printf("这句话里单引号和双引号以外的字符共有: %d 个\n", charcount);

    return 0;
}