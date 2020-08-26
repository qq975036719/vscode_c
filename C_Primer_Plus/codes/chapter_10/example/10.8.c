// 指针地址
#include <stdio.h>
#define SIZE 4

int main(void)
{
    short dates[SIZE];
    short *pti;
    short index;
    double bills[SIZE];
    double *ptf;
    pti = dates;    // 把数组的地址赋值给指针
    ptf = bills;
    printf("%23s %15s\n", "short", "double");
    for (index = 0; index < SIZE; index++)
        printf("pointers + %d: %10p %10p\n",
               index, pti + index, ptf + index);
    return 0;
    // 指针的加法是以存储单元为单位而不是字节为单位
    // 即指针+1 == 下一个元素的地址 != 下一个字节的二地址
}