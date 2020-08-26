#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} coordinate;

void flush_cordinate(coordinate *p, int x, int y);    // 刷新坐标
int main(void)
{
    int x, y;                   // Madeline的坐标
    int n, k;                   // 输入的数据
    char direction;             // 移动方向
    coordinate madeline;        // 存储madeline的坐标
    coordinate badeline;        // 存储badeline的坐标
    coordinate *pm = &madeline;
    coordinate *pb = &badeline;

    // 初始化生成Madeline的坐标
    x = 0;
    y = 0;

    // 读入数据
    scanf("%d %d", &n, &k);
    // 生成一个临时数组，用于存储第n-k秒时的madeline的坐标
    coordinate *temp = (coordinate *)malloc((n + 1) * sizeof(coordinate));
    
    flush_cordinate(pm, x, y);  // 生成madeline的坐标
    flush_cordinate(&temp[0], x, y);  // 存储madeline的初始坐标

    // 清理输入行
    while (getchar() != '\n')
        continue;

    for (int i = 1; i <= n; i++) {
        // 读入方向
        direction = getchar();
        
        switch(direction) {
            case 'L':
                x -= 1;
                break;
            case 'R':
                x += 1;
                break;
            case 'U':
                y += 1;
                break;
            case 'D':
                y -= 1;
                break;
            case 'S':
                break;
        }
        // 每移动一次 -- 刷新一次madeline的坐标
        flush_cordinate(pm, x, y);
        // 刷新了madeline的坐标后 -- 存储到临时数组中
        flush_cordinate(&temp[i], x, y);
        // 第k秒时,badeline诞生,其初始位置为madeline开始的位置
        if (i >= k) {
            flush_cordinate(pb, temp[i-k].x, temp[i-k].y);
            // 判断是否相遇
            if ((madeline.x == badeline.x) &&
                (madeline.y == badeline.y))
            {
                printf("no\n");
                break;
            }
        }
        // 第n秒的情况
        if (i == n) {
            flush_cordinate(pb, temp[i-k].x, temp[i-k].y);
            // 判断是否相遇
            if ((madeline.x == badeline.x) &&
                (badeline.x == badeline.y))
            {
                printf("no\n");
                break;
            }
            else {
                printf("yes\n");
                break;
            }
        }
    }
    free(temp);

    return 0;
}

void flush_cordinate(coordinate *p, int x, int y)
{
    p->x = x;
    p->y = y;
}