// 让编译器计算元素个数
#include <stdio.h>

int main(void)
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int index = 0;
    for (index = 0; index < sizeof(days) / sizeof(days[0]); index++) {
        printf("%d月有%d天\n", index + 1, days[index]);
    }
    // sizeof(days) -- 计算days数组的总大小(字符为单位)
    // sizeof(days[0]) -- 计算days数组的单个元素的大小(字符为单位)
    // sizeof(days) / sizeof(days[0]) -- 总大小除以单位大小即数组的个数
    return 0;
}