// 函数: Fibonacci() -- 显示斐波那契数列的第n项
#include <stdio.h>

int main(void)
{
    void Fibonacci(int n);
    int n;
    printf("请输入项数: ");
    while (scanf("%d", &n) == 1) {
        Fibonacci(n);
        printf("\n请输入项数: ");
    }

    return 0;
}

void Fibonacci(int n)
{
    unsigned long answer = 0;
    unsigned long pre1 = 1;
    unsigned long pre2 = 1;
    int count = 0;
    if (n > 2) {
        printf("%d %d ", 1, 1);
        for (int i = 0; i < n - 2; i++) {
            answer = pre1 + pre2;
            pre1 = pre2;
            pre2 = answer;
            printf("%lu ", answer);
            count++;
            if (count == 10) {
                putchar('\n');
                count = 0;
            }
        }
    }
    else
        for (int i = 0; i < n; i++)
            printf("%d ", 1);
}