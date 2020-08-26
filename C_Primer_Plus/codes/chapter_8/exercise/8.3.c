// 输出大小写字母的个数
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int upper = 0;          // 大写字母的个数
    int lower = 0;          // 小写字母的个数
    char ch;
    while ((ch = getchar()) != EOF) {
        if (isupper(ch))
            upper++;
        else if (islower(ch))
            lower++;
    }
    printf("大写字母个数: %d, 小写字母个数: %d",
           upper, lower);
}