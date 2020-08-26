// 厘米转换成英尺和英寸
#include <stdio.h>
int main(void)
{
    int cm;
    scanf("%d", &cm);

    int foot = cm / 30.48;
    int inch = ((cm / 30.48) - foot) * 12;

    printf("%d %d", foot, inch);

    getchar();
    getchar();
    return 0;
}