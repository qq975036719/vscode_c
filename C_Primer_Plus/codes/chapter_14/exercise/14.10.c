// 实现函数指针数组
#include <stdio.h>

void f1(void);
void f2(void);
void f3(void);
void f4(void);
void f5(void);

int main(void)
{
    void (*pf[5])(void) = {f1, f2, f3, f4, f5};
    int index;

    printf("请选择要调用的函数(1-5): ");
    scanf("%d", &index);
    pf[index - 1]();

    return 0;
}

void f1(void)
{
    printf("f1");
}

void f2(void)
{
    printf("f2");
}

void f3(void)
{
    printf("f3");
}

void f4(void)
{
    printf("f4");
}
void f5(void)
{
    printf("f5");
}