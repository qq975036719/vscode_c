// 参数错误的时候会出现的情况
#include <stdio.h>
int main(void)
{
    int m = 4;
    int n = 5;
    float i = 7.0f;
    float j = 8.0f;

    printf("%d\n", m, n);       /* 参数过多 */
    printf("%d %d %d\n", m);       /* 参数过少*/
    printf("%d %d\n", i, j);    /* 值的类型不匹配符*/

    getchar();

    return 0;
}