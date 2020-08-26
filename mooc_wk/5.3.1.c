// 计算调和数列的前n项和
#include <stdio.h>

int main(void)
{
    int n, i;
    double sign = 1.0;
    double sum = 0.0;
    printf("你想求前几项的和？");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        sum += sign / i;
        // sign = -sign;
    }
    printf("f(%d) = %f\n", n, sum);

    getchar();
    getchar();
    return 0;
}