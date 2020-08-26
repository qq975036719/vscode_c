// 实现数组中删除某一元素
#include <stdio.h>
#define SIZE 15

int my_del(int a[], int b, int len)
{
    if (len == 0)
        return 0;
    
    int target = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] == b)
            target = i;
    }
    for (int k = target; k < len - 1; k++)
        a[k] = a[k + 1];
    
    return 1;
}

int main(void)
{
    int a[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    puts("删除前数组内容如下：");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", a[i]);
    putchar('\n');

    puts("删除某一元素后数组内容如下：");
    my_del(a, 6, SIZE);
    for (int i = 0; i < SIZE - 1; i++)
        printf("%d ", a[i]);

    return 0;
}