// 自定义不换行的“puts()”函数 -- put1()函数
#include <stdio.h>

void put1(const char * string)
{
    while (*string)
        putchar(*string++);
}