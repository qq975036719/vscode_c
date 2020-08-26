// 递归演示
#include <stdio.h>

int main(void)
{
    void up_and_down(int num);

    up_and_down(1);
    return 0;
}

void up_and_down(int num)
{
    printf("Level: %d: n location %p\n", num, &num);
    if (num < 4)
        up_and_down(num + 1);
    printf("Level: %d: n location %p\n", num, &num);
}