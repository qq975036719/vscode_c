// 计算调和数列的值
#include <stdio.h>

int main(void)
{
    int n;
    double sum1, sum2, sign;
    printf("请输入要求和的项数: ");
    scanf("%d", &n);
    while (n > 0) {
        sum1 = 0.0;
        sum2 = 0.0;
        sign = 1.0;
        
        // 计算f(n)
        for (int i = 1; i <= n; i++) {
            sum1 += sign / i;
        }
        //计算g(n)
        for (int i = 1; i <= n; i++) {
            sum2 += sign / i;
            sign = -sign;
        }
        
        printf("f(%d) = %f\n", n, sum1);
        printf("g(%d) = %f\n", n, sum2);

        printf("请输入要求和的项数: ");
        scanf("%d", &n);
    }

    return 0;
}