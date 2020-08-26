// 在数组中读入8个整数，然后倒序打印这8个整数
#include <stdio.h>

int main(void)
{
    int ch[8];
    printf("请输入8个整数,此程序会倒序输出这8个字符: ");

    // 读入8个整数到数组中
    for (int i = 0; i < 8; i++)
        scanf("%d", &ch[i]);

    // 倒序输出8个整数
    for (int i = 7; i >= 0; i--)
        printf("%d ", ch[i]);

    return 0;
}