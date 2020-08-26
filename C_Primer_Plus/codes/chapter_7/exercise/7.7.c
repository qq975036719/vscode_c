// 输入一周工作小时数, 打印工资总额、税金和净收入
#include <stdio.h>
#define RATE1 0.15              // 前300美元的税率
#define RATE2 0.20              // 续150美元的税率
#define RATE3 0.25              // 超过450美元的税率
#define BASE1 RATE1 * 300       // 300美元的税金
#define BASE2 BASE1+RATE2*150   // 450美元的税金
#define MONEY 10.00             // 基本工资 $10.00/小时
#define OVER_MONEY MONEY*40     // 工作完40小时的工资
#define ADD_MONEY 15.00         // 加班工资

int main(void)
{
    float hour;
    float money = 0;
    float rate_money = 0;
    float pure_money = 0;
    
    printf("输入你一周工作的小时数，该程序会打印");
    printf("你的工资总额、税金和净收入\n");
    printf("请输入你的工作小时数: ");

    while (scanf("%f", &hour) == 1) {
        if (hour > 0 && hour <= 30) {
            money = hour * MONEY;                           // 30小时以内的基本工资
            rate_money = money * RATE1;                     // 30小时以内的税金
            pure_money = money - rate_money;                // 30小时以内的净收入
        }
        else if (hour <= 40) {
            money = hour * MONEY;                           // 30-40小时的工资
            rate_money = 300*RATE1 + (money-300) * RATE2;   // 30-40小时的税金
            pure_money = money - rate_money;                // 30-40小时的净收入
        }
        else {
            money = OVER_MONEY + ADD_MONEY * (hour-40); 
            if (money <=450) {
                rate_money = 300 * RATE1 + (money - 300) * RATE2;
                pure_money = money - rate_money;
            }           
            else {
                rate_money = 300 * RATE1 + 150 * RATE2 + (money - 450) * RATE3;
                pure_money = money - rate_money;
            }
        }
        printf("工资总额    税金    净收入\n");
        printf("%4.2f %10.2f %8.2f\n", money, rate_money, pure_money);
        printf("请输入你的工作小时数: ");
    }

    getchar();
    getchar();
    return 0;
}