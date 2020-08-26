// 使用memcpy和memmove
#include <stdio.h>
#include <string.h>
#define SIZE 10
// C11新特性 -- 用于判断当前系统的double是否是int的两倍
// _STATIC_ASSERT(sizeof(double) == (2 * sizeof(int)), "double not twice int size!");

void show_array(const int ar[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", ar[i]);
        if ((i + 1) % 10 == 0)
            putchar('\n');
    }
    putchar('\n');
}

int main(void)
{
    int values[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target[SIZE];
    double curious[SIZE / 2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30};

    // values --> target -- memcpy()
    puts("memcpy() used:");
    puts("values (original data): ");
    show_array(values, SIZE);
    memcpy(target, values, SIZE*sizeof(int));
    puts("target (copy of values): ");
    show_array(target, SIZE);

    // memmove()
    puts("\nUsing memove() with overlapping ranges:");
    memmove(values + 2, values, (SIZE / 2) * sizeof(int));
    puts("values -- elements 0-4 copied to 2-6:");
    show_array(values, SIZE);

    // memcpy() -- curious --> target
    puts("\nUsing memcpy() to copy double to int:");
    memcpy(target, curious, (SIZE / 2) * sizeof(double));
    puts("target -- 5 double into 10 int positions:");
    show_array(target, SIZE / 2);
    show_array(target + 5, SIZE / 2);

    return 0;
}


