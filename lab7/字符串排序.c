// 实现字符串的排序 -- 从小到大排序
#include <stdio.h>
#include <string.h>
#define SIZE 100

void SortStr(char *str, int len)
{
    char *pst = str;

    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (pst[i] > pst[j]) {
                char temp = pst[i];
                pst[i] = pst[j];
                pst[j] = temp;
            }
        }
    }
}

int main(void)
{
    char str[SIZE] = "fcabizxbvjvlmmzpsqtsx";
    int len = strlen(str);

    puts("排序前的字符串：");
    puts(str);

    puts("排序后的字符串：");
    SortStr(str, len);
    puts(str);

    return 0;
}