// 位操作显示二进制
#include <stdio.h>
#include <limits.h>

char *itobs(int n, char *st);
void show_bstr(char *st);
int main(void)
{
    int num;
    char st[sizeof(int) * CHAR_BIT + 1];

    printf("请输入一个数字: ");
    while (scanf("%d", &num) == 1) {
        itobs(num, st);
        printf("%d is ", num);
        show_bstr(st);
        putchar('\n');
        printf("请输入一个数字: ");
    }
}

char *itobs(int n, char *st)
{
    const static int size = sizeof(int) * CHAR_BIT;

    for (int i = size - 1; i >= 0; i--, n >>= 1)
        st[i] = (n & 01) + '0';
    st[size] = '\0';

    return st;
}

void show_bstr(char *st)
{
    int i = 0;

    while (st[i]) {
        putchar(st[i]);

        if (++i % 4 == 0 && st[i])
            putchar(' ');
    }
}