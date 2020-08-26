// 计算经过一定分钟后的时间
#include <stdio.h>
int main(void)
{
    int old_time, min;                                      // 定义现在的时间和待增加的分钟数
    scanf("%d %d", &old_time, &min);                        // 读入数据
    
    int new_time = (old_time / 100)*60 + (old_time % 100);  // 将时间全部化成分钟方便计算
    new_time += min;
    new_time = (new_time / 60) * 100 + (new_time % 60);     // 将新的时间的分钟数化成小时+分钟的形式

    printf("%d", new_time);

    getchar();
    getchar();
    return 0;
}