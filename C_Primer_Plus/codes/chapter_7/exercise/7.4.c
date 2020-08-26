/* 用感叹号替换句号，两个感叹号替换原来的感叹号
   并打印替换的次数 */
#include <stdio.h>

int main(void)
{
    int point_ct = 0;
    int tan_ct = 0;
    char ch;
    printf("此程序会替换这句话的所有句号为");
    printf("感叹号,所有感叹号为双感叹号\n");
    printf("请输入一句话: ");

    while ((ch = getchar()) != '#') {
        if (ch == '.') {
            printf("!");
            point_ct++;     // 统计句号替换次数
        }
        else if (ch == '!') {
            printf("!!");
            tan_ct++;       // 统计感叹号替换次数
        }
        else
            printf("%c", ch);
    }
    printf("替换句号%d次, 感叹号%d次", point_ct, tan_ct);

    return 0;
}