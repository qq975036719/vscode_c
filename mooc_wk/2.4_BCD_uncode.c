// 以BCD解码10进制数字 -- BCD即十六进制中0~153范围内的数字
#include <stdio.h>
int main(void)
{
    int dec_num;
    scanf("%d", &dec_num);
    int BCD = (dec_num / 16) * 10 + (dec_num % 16);

    // 多种实现BCD解码的方式
    printf("%d\n", BCD);
    printf("%x\n", dec_num);
    printf("%#x\n", dec_num);

    getchar();
    getchar();
    return 0;
}