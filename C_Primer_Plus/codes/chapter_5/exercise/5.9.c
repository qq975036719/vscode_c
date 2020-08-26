// 摄氏温度和开氏温度转换
#include <stdio.h>

int main(void)
{
    void Temperatures(double temp);
    double fah;
    printf("请输入一个华氏温度: ");

    while (scanf("%lf", &fah) == 1) {
        Temperatures(fah);
        printf("请输入下一个华氏温度(输入q退出程序): ");
    }

    return 0;
}

void Temperatures(double temp)
{
    const double fah_2_cel = 5.0 / 9.0;
    const double fah_2_kel = 273.16;
    double cel = (temp - 32.0) * fah_2_cel;
    double kel = cel + fah_2_kel;
    printf("fah = %.2lf\tcel = %.2lf\tkel=%.2lf\n", temp, cel, kel);
}