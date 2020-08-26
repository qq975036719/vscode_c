// make_array() 和 show_array()函数
#include <stdio.h>
#include <stdlib.h>

int *make_array(int elem, int val);         // 用于创建一个数组并初始化所有元素为val
void show_array(const int ar[], int n);     // 打印数组

int main(void)
{
    int *pa;
    int size;
    int value;

    printf("Enter the number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0) {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);

        if (pa) {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements(<1 to quit): ");
    }
    printf("Done.\n");

    return 0;
}

int *make_array(int elem, int val)
{
    int *array = (int *)malloc(elem * sizeof(int));
    if (array == NULL)
        return NULL;
    for (int i = 0; i < elem; i++)
        array[i] = val;

    return array;
}

void show_array(const int ar[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%-4d", ar[i]);
        if ((i + 1) % 10 == 0)
            putchar('\n');
    }
    putchar('\n');
}