/* 用感叹号替换句号，两个感叹号替换原来的感叹号
   并打印替换的次数 -- 使用switch case实现*/
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
        switch(ch) {
            case '!':
                printf("!!");
                tan_ct++;
                break;
            case '.':
                printf("!");
                point_ct++;
                break;
            default:
                printf("%c", ch);
                break;
        }
    }
    printf("\n替换句号%d次, 感叹号%d次", point_ct, tan_ct);

    return 0;
}