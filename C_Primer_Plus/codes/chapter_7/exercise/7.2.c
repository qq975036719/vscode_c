// 打印“字符-ASCii码”组合
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int count = 0;
    printf("请输入一个字符(#结束): ");
    while ((ch = getchar()) != '#') {
        if (count++ % 8 == 0)        // 每8个换一次行, count == 0时会换行
            printf("\n");            // 所以要用count++来判断
        
        if (ch == '\n')              // 当字符为换行符的处理
            printf("'\\n'-%d\t", ch);
        
        else if (ch == '\t')         // 当字符为制表符的处理
            printf("'\\t'-%d\t", ch);
        
        else
            printf("'%c'-%d\t", ch, ch); // 打印结果
    }
    return 0;
}