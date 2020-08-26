// 不适用全局变量修改程序清单12.4 -- global.c
#include <stdio.h>

void critic(int *num);

int main(void)
{
    int units = 0;

    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        critic(&units);
    printf("You must have looked it up!\n");

    return 0;
}

void critic(int *num)
{
    printf("No luck, my friend. Try again.\n");
    scanf("%d", num);
}