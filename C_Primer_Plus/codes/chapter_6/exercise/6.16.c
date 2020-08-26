// 计算复利追上单利的时间以及差额
#include <stdio.h>

int main(void)
{
    const float MONEY = 100.0;
    const float SIMPLE = 0.1;
    const float COMPOUND = 0.05;
    
    int year;
    double daphne, deirdre, difference;
    daphne = MONEY;
    deirdre = MONEY;

    year = 1;
    printf("今年是第%d年!\n", year);
    printf("Daphne的总金额是: %.2lf\nDeirdre的总金额是: %.2lf\n\n",
           daphne, deirdre);

    for (year = 1; deirdre <= daphne; year++) {
        daphne += MONEY * SIMPLE;
        deirdre = deirdre * (1 + COMPOUND);
        difference = daphne - deirdre;
        printf("今年是第%d年, 两人金额的差值是: %.2lf\n\n",
               year + 1, difference);
    }
    printf("在第%d年,Deirdre 追上 Daphne了,金额差为%.2lf\n\n",
           year, -difference);
    printf("Daphne总金额为: %.2lf\n", daphne);
    printf("Deirdre总金额为: %.2lf\n", deirdre);

    return 0;
}