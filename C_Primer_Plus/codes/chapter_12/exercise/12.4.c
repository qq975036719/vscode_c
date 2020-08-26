// 返回函数被调用的次数
#include <stdio.h>

void test(void);

int count = 0;

int main(void)
{
    while (count < 99)
        test();

    printf("函数test()被调用了%d次", count);
    
    return 0;
}

void test(void)
{
    printf("我被调用啦!\n");
    count++;
}