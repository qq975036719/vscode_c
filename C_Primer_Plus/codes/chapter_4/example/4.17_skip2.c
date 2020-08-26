// scanf()中用 * 跳过读入的数据
#include <stdio.h>

int main(void)
{
    int n;
    printf("请输入三个数字：\n");
    scanf("%*d %*d %d", &n);
    printf("你输入的第三个数字是：%d", n);
    // scanf()中用 * 会跳过读取数据
    // 这里的scanf()跳过了第一个和第二个数据
    
    getchar();
    getchar();
    return 0;
}