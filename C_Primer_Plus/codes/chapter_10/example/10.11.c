// 数组元素之和 -- 另一种实现方法
#include <stdio.h>
#define SIZE 10

int main(void)
{
    long sump(int *begin, int *end);
    int numbers[SIZE] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
    long answer;
    answer = sump(numbers, numbers + SIZE);
    printf("数组元素的总和为: %ld", answer);

    return 0;
}

long sump(int * begin, int * end)
{
    long total = 0;
    while (begin < end) {
        total += *begin;    // 对应的元素相加
        begin++;            // 指针指向下一个元素
        // total += *begin++    -- 这样写等价于*(begin++)
    }
    return total;
}