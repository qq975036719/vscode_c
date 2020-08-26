// 猜数游戏
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int num, answer, count;
    srand(time(0));
    answer = rand() % 100 + 1;
    count = 0;
    
    do{
        printf("请输入一个数字: ");
        scanf("%d", &num);
        count++;
        if (num > answer)
            printf("猜大了，再试试吧！\n");
        else if (num < answer)
            printf("猜小了，再试试吧！\n");
    } while (num != answer);
    printf("恭喜你猜中了，你用了%d次，答案是: %d", count, answer);

    return 0;
}