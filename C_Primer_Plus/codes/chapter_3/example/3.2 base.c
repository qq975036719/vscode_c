// 分别以十进制、八进制、十六进制打印十进制数字100
#include <stdio.h>
int main(void)
{
    int x = 100;
    printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
    printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);
    
    getchar();
    return 0;
}