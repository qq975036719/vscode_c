// 使用局部静态变量
#include <stdio.h>

void trystat(void);
int main(void)
{
    for (int i = 0; i < 3; i++) {
        printf("第%d轮\n", i + 1);
        trystat();
    }

    return 0;
}

void trystat(void)
{
    int fade = 1;
    static int stay = 1;

    printf("fade = %d\tstay = %d\n", fade++, stay++);
}