// 通过命令行参数进行幂运算
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double answer = 1;

    if (argc < 2)
        printf("你未输入参数!");
    else if (argc != 3)
        printf("请输入两个参数,第一个参数是底数，第二个是指数\n");
        
    double f = atof(argv[1]);
    int num = atoi(argv[2]);
    for (int i = 0; i < num; i++)
        answer *= f;

    printf("%g的%d次幂 = %g\n", f, num, answer);
    
    return 0;
}