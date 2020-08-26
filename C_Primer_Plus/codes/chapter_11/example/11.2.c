// 验证字符串是不是指针
#include <stdio.h>

int main(void)
{
    printf("%s  %p  %c\n", "we", "are", *"family!");

    return 0;
}