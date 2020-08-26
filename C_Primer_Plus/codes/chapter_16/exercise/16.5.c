// 随机选取数组中指定个数的元素
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void select_elem(int ar[], int size, int n)
{
    int *masks = (int *)malloc(sizeof(int) * size);

    srand(time(0));
    while (n > 0) {
        int index = rand() % size;
        if (masks[index] != 0)
            continue;
        else
            masks[index] = 1;
        printf("Selected num: %d\n", ar[index]);
        n--;
    }
}

int main(void)
{
    int ar[SIZE];
    int num;

    for (int i = 0; i < SIZE; i++)
        ar[i] = i;

    printf("请输入随机选择的个数: ");
    scanf("%d", &num);

    select_elem(ar, SIZE, num);

    return 0;
}