// 计算水的夸脱数对应的水分子数量
// 1个水分子质量是3.0e-23克，1夸脱水是950克
#include <stdio.h>
int main(void)
{
    float mass_mol = 3.0e-23;       // 水分子的质量
    float mass_qt = 950;            // 1夸脱水的质量
    float quart;
    float molecules;
    printf("请输入水的夸脱数： ");
    scanf("%f", &quart);

    molecules = quart * mass_qt / mass_mol;
    printf("%.2f夸脱水对应的水分子的数量为：%e", quart, molecules);

    getchar();
    getchar();
    return 0;
}