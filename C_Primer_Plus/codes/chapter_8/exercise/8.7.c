// 给出一个供选择的工资等级菜单
#include <stdio.h>
#define LEVEL1 8.75     // 工资等级1 -- 每小时8.75美金
#define LEVEL2 9.33     // 工资等级2 -- 每小时9.33美金
#define LEVEL3 10.00    // 工资等级3 -- 每小时10.00美金
#define LEVEL4 11.20    // 工资等级4 -- 每小时11.20美金
#define RATE1 0.15      // 前300美金的税率
#define RATE2 0.20      // 300-450美金的税率
#define RATE3 0.25      // 450以后的税率
#define EXTRA_HOUR 1.5  // 加班的工作小时

int main(void)
{
    float hour;
    float salary, tax, taxed_salary;
    float level = 0.0;
    char choice;

    // 打印提示信息, 共用户输入选项
    printf("*******************************************************\n");
    printf("请输入下列选项,选择你想查看的工资等级: \n");
    printf("a) $8.75/时\t\t\tb) $9.33/时\n");
    printf("c) $10.00/时\t\t\td) $11.20/时\n");
    printf("q) 退出程序\n");
    printf("*******************************************************\n");
    // 读入选项
    while (scanf("%c", &choice) == 1) {
        while (getchar() != '\n')       // 跳过剩余的无用输入
            continue;
        // 判断用户输入5时选择退出程序
        if (choice == 'q')
            break;
        // 判断是否输入正确的选项
        if (choice < 'a' || choice > 'd') {
            printf("请输入正确的选项!\n");
            continue;
        }
        // 读入工作时长
        printf("请输入你的工作时长: ");
        scanf("%f", &hour);
        // 分情况计算工资情况
        switch (choice) {       // 根据choice的选项来选定level
        case 'a':
            level = LEVEL1;
            break;
        case 'b':
            level = LEVEL2;
            break;
        case 'c':
            level = LEVEL3;
            break;
        case 'd':
            level = LEVEL4;
            break;
        }
        // 工资情况判断
        if (hour > 0 && hour <= 40) {             // 工作时长在0-40的情况 -- 不加班
            salary = hour * level;
            if (salary <= 300) {                  // 税率1
                tax = salary * RATE1;
                taxed_salary = salary - tax;
            }
            else if (salary<=450) {               // 税率2
                tax = 300 * RATE1 + (salary - 300) * RATE2;
                taxed_salary = salary - tax;
            }
            else {                                // 税率3
                tax = 300 * RATE1 + 150 * RATE2 + (salary - 450) * RATE3;
                taxed_salary = salary - tax;
            }
        }
        else {                                    // 工作时长大于40的情况 -- 加班
            salary = (40 + (hour - 40) * EXTRA_HOUR) * level;
            if (salary <= 300) {                  // 税率1
                tax = salary * RATE1;
                taxed_salary = salary - tax;
            }
            else if (salary<=450) {               // 税率2
                tax = 300 * RATE1 + (salary - 300) * RATE2;
                taxed_salary = salary - tax;
            }
            else {                                // 税率3
                tax = 300 * RATE1 + 150 * RATE2 + (salary - 450) * RATE3;
                taxed_salary = salary - tax;
            }
        }
        // 输出工资情况信息
        printf("\n工资信息如下: \n");
        printf("\n工资总额\t\t税金\t\t净收入\n");
        printf("%4.2f %20.2f %18.2f\n\n", salary, tax, taxed_salary);
        // 重复打印提示信息, 共用户输入选项
        printf("*******************************************************\n");
        printf("请输入下列选项,选择你想查看的工资等级: \n");
        printf("a) $8.75/时\t\t\tb) $9.33/时\n");
        printf("c) $10.00/时\t\t\td) $11.20/时\n");
        printf("q) 退出程序\n");
        printf("*******************************************************\n");
    }
    printf("程序已退出！");

    getchar();
    getchar();
    return 0;
}