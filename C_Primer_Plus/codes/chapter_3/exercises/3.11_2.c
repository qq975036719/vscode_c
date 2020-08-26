// ASCⅡ值转换成字符
#include <stdio.h>
int main(void)
{
    int i;
    printf("请输入一个ASCⅡ值：");
    scanf("%d", &i);
    printf("ASCⅡ值:%d 对应的字符为:%c", i, i);
    
    getchar();
    getchar();
    
    return 0;
}