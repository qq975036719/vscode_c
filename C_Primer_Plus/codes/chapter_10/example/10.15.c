// 指针表示形式的比较
#include <stdio.h>

int main(void)
{
    int array[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};
    // array和array+1的地址
    printf("array = %16p\tarray + 1 = %16p\n",
           array, array + 1);
    // array[0]和array[0]+1(array[0][1])的地址
    printf("array[0] = %16p\tarray[0] + 1 = %16p\n",
           array[0], array[0] + 1);
    // array[0][0]的地址
    printf("&array[0][0] = %16p\n", &array[0][0]);
    // array[0][0]的地址 -- 用(int *) grid表示
    printf("(int *) array = %16p\n", (int *)array);

    return 0;
}