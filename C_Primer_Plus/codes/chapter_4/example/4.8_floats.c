// float的修饰符展示
#include <stdio.h>

int main(void)
{
    const double RENT = 3852.99;  // const变量 -- 只读

    printf("*%f*\n", RENT);
    printf("*%e*\n", RENT);
    printf("*%4.2f*\n", RENT);
    printf("*%3.1f*\n", RENT);
    printf("*%3.2f*\n", RENT);
    printf("*%3.3f*\n", RENT);
    printf("*%5.1f*\n", RENT);
    printf("*%5.2f*\n", RENT);
    printf("*%8.2f*\n", RENT);
    printf("*%10.3f*\n", RENT);
    printf("*%10.3e*\n", RENT);
    printf("*%5.3e*\n", RENT);
    printf("*%+4.2f*\n", RENT);
    printf("*%010.2f*\n", RENT);

    getchar();
    return 0;
}