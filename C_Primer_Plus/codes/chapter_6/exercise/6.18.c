// 计算社交圈朋友数超过邓巴数
#include <stdio.h>
#define DENBARS 150

int main(void)
{
    int friends = 5;
    int i;
    for (i = 1; friends <= DENBARS; i++) {
        printf("第%d周总朋友数: %d\n", i, friends);
        friends -= i;
        friends *= 2; 
    }
    printf("第%d周符合题意\n", i - 1);

    return 0;
}