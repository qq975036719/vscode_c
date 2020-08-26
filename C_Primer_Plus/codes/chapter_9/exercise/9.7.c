// 函数: 返回字母的位置
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int get_location(char ch);
    char ch;
    printf("请输入一个字母: ");
    while ((ch = getchar()) != EOF) {
        printf("%d\n", get_location(ch));
        while (getchar() != '\n')
            continue;
        printf("请输入一个字母: ");
    }
}

int get_location(char ch)
{
    int location;
    if (isupper(ch))
        location = ch - 'A' + 1;
    else if (islower(ch))
        location = ch - 'a' + 1;
    else
        location = -1;

    return location;
}