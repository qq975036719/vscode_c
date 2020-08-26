// string_in()函数 -- 检测一个字符串中是否包含某个子串 -- 有则返回子串的第一个字符地址
#include <stdio.h>
#include <string.h>
#define SIZE 80

char *string_in(char *st1, char *st2);
int main(void)
{
    char st1[SIZE];
    char st2[SIZE];
    char *res;

    printf("请输入一个字符串: ");
    fgets(st1, SIZE, stdin);
    printf("请输入待查找的子串: ");
    fgets(st2, SIZE, stdin);
    while (*st1 != '\n') {
        res = string_in(st1, st2);
        if (res) {
            printf("字符串中该子串的地址为: %p\n", res);
            printf("该地址上的值为: \"%c\"\n", *res);
        }
        else {
            printf("字符串中找不到子串 ");
            puts(st2);
        }
        // 重新输入
        printf("请输入一个字符串: ");
        fgets(st1, SIZE, stdin);
        printf("请输入待查找的子串: ");
        fgets(st2, SIZE, stdin);
    }

    return 0;
}
char *string_in(char *st1, char *st2)
{
    int count = 0;
    int sub_len = strlen(st2)-1;

    while (*st1 && count < sub_len) {
        if (*(st1 + count) == *(st2 + count))
            count++;
        else {
            count = 0;
            st1++;
        }
    }
    if (count == sub_len)
        return st2;
    else
        return NULL;
}