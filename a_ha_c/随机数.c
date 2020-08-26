#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a, b, sum=10;
    srand((unsigned)time(NULL));
    a = rand()%100;
    
    printf("--------游戏开始，你有10次机会-------------------------------------\n");
    printf("--------游戏规则:每次输入一个0~99之间的数字，猜中即算获胜！--------\n");
    
    while(1)
    {
        sum--;
        scanf("%d", &b);
        
        if (b>a){
            printf("大了，请继续!\n");
            printf("你还有%d次机会\n", sum);
        }
        
        if (b<a){
            printf("小了，请继续!\n");
            printf("你还有%d次机会\n", sum);
        }
        
        if (a==b)
        {
            printf("恭喜你答对了！\n");
            break;
        }
        
        if (sum == 0){
            printf("很遗憾，你的机会已经用尽了 -->_<--");
            break;
        }
    }
    return 0;
}

