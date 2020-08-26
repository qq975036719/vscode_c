// 倒序打印一行输入
#include <stdio.h>

int main(void)
{
    char ch[256];
    printf("请输入一行话,此程序会倒序输出: ");
    
    int i = 0;
    do {
        scanf("%c", &ch[i]);
    } while (ch[i] != '\n' && ++i);
    // 利用scanf读取%c的特性,遇到换行符时就让循环停止
    
    printf("逆序输出的结果是: \n");
    for (i--; i >= 0; i--)
        printf("%c", ch[i]);

    return 0;
}