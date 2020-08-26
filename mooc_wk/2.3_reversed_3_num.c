// 按位逆序输出三位数字
#include <stdio.h>
int main(void)
{
    int num;
    scanf("%d", &num);

    int n1, n2, n3;
    n1 = num / 100;
    n2 = (num / 10) % 10;
    n3 = num % 10;

    int new_num = n3 * 100 + n2 * 10 + n1;
    
    printf("%d", new_num);

    getchar();
    getchar();

    return 0;
}
