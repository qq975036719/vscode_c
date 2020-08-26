// 此程序中包含三个函数
#include <stdio.h>
void ic(void);
void br(void);
int main(void)
{
    printf("Brazil, Russia,\t");
    ic();
    printf("India, China,\n");
    br();

    return 0;
}

void br(void)
{
    printf("Brazil, Russia\n");
}

void ic(void)
{
    printf("India, China\n");
}