// 二进制字符串转换成数值
#include <stdio.h>

int btoi(char *pb);
int main(void)
{
    char *pbin = "01001001";

    printf("%d\n", btoi(pbin));

    return 0;
}

int btoi(char *pb)
{
    int sum = 0;

    while (*pb) {
        sum *= 2;
        sum += *pb++ - '0';
    }

    return sum;
}

