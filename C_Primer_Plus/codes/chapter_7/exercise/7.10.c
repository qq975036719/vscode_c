// 分类计算用户应缴纳的税金
#include <stdio.h>

int main(void)
{
    // 定义需要用到的const变量(常量)
    const unsigned int SINGLE = 17850;          // 单身
    const unsigned int HOUSE_HOLDER = 23900;    // 户主
    const unsigned int MARRIED = 29750;         // 已婚
    const unsigned int DIVORCED = 14875;        // 离婚
    // 声明需要的函数原型
    void calc_tax(unsigned int type, float salary);
    // 定义变量
    char type;      // 税金缴纳的类型
    float salary;   // 工资

    do {
        // 让用户选择税金缴纳的类型
        printf("此程序用于计算您应缴纳的税金,首先请选择类型: \n");
        printf("1) 单身\t2) 户主\t3) 已婚\t4) 离婚\t5) 退出程序\n");
        scanf("%c", &type);

        // 按输入的类型来分情况计算税金
        switch (type) {
            case '1':                           // 单身
                printf("请输入您的工资: ");
                scanf("%f", &salary);
                calc_tax(SINGLE, salary);
                break;
            case '2':                           // 户主
                printf("请输入您的工资: ");
                scanf("%f", &salary);
                calc_tax(HOUSE_HOLDER, salary);
                break;
            case '3':                           // 已婚
                printf("请输入您的工资: ");
                scanf("%f", &salary);
                calc_tax(MARRIED, salary);
                break;
            case '4':                           // 离婚
                printf("请输入您的工资: ");
                scanf("%f", &salary);
                calc_tax(DIVORCED, salary);
                break;
            case '5':
                break;
            default:
                printf("请输入有效的选项!\n\n");
                getchar();
                break;
        }
    } while (type != '5');
    printf("程序已退出!");

    return 0;
}

// 定义计算税金的函数
void calc_tax(unsigned int type, float salary)
{
    float tax, taxed_salary;
    if (salary <= type) {
        tax = salary * 0.15;
        taxed_salary = salary - tax;
    }
    else {
        tax = type * 0.15 + (salary - type) * 0.28;
        taxed_salary = salary - tax;
    }

    printf("您应缴纳的税金为: %.2f, 税后净收入为: %.2f\n\n",
           tax, taxed_salary);
}