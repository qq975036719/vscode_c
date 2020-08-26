// 计算下载时间
#include <stdio.h>

int main(void)
{
    float speed, memory, time;
    printf("请输入下载速度(MB/s): ");
    scanf("%f", &speed);

    printf("请输入待下载文件的大小(MB): ");
    scanf("%f", &memory);

    time = memory / speed;
    printf("At %.2f MB/s, a file of %.2f MB download in %.2f seconds.",
           speed, memory, time);

    getchar();
    getchar();
    return 0;
}