#include <stdio.h>

int main(void)
{
    int num, ret;
    printf("输入要逆序的数字: ");
    scanf("%d", &num);
    ret = 0;

    while (num != 0) {
        ret = ret * 10 + (num % 10);
        // printf("%d", ret);
        num /= 10;
    }
    printf("%d", ret);
    
    getchar();
    return 0;
}