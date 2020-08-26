// 秒钟转换成分钟，秒钟
#include <stdio.h>
#define SEC_TO_MIN 60       //1min = 60s
int main(void)
{
    int sec, min, left;
    printf("请输入秒钟数(<=0时退出程序): ");
    scanf("%d", &sec);

    while (sec>0)
    {
        min = sec / 60;     //截取分钟数
        left = sec % 60;    //截取剩余的秒钟数
        printf("%d秒 = %d分,%d秒\n", sec, min, left);
        printf("请输入下一个秒钟数(<=0时退出程序): ");
        scanf("%d", &sec);
    }
    printf("程序已退出！\n");
    
    getchar();
    getchar();
    return 0;
}