// 计算器小程序
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    // 函数原型
    void show_menu();   // 显示输入提示信息
    float get_num();    // 获取用户输入的数字

    // 变量
    char choice;        // 用户的选择
    char ch;

    do {
        float num1, num2;
        show_menu();
        choice = getchar();
        while ((getchar()) != '\n')        // 过滤无效输入
            continue;
        switch (choice) {
            case 'a':
            case 'A':
                printf("请输入被加数: ");
                num1 = get_num();
                printf("请输入加数: ");
                num2 = get_num();
                printf("%g + %g = %g\n",
                       num1, num2, num1 + num2);
                break;
            case 'b':
            case 'B':
                printf("请输入被减数: ");
                num1 = get_num();
                printf("请输入减数: ");
                num2 = get_num();
                printf("%g - %g = %g\n",
                       num1, num2, num1 - num2);
                break;
            case 'c':
            case 'C':
                printf("请输入被乘数: ");
                num1 = get_num();
                printf("请输入乘数: ");
                num2 = get_num();
                printf("%g * %g = %g\n",
                       num1, num2, num1 * num2);
                break;
            case 'd':
            case 'D':
                printf("请输入被除数: ");
                num1 = get_num();
                printf("请输入除数: ");
                num2 = get_num();
                while (num2 == 0) {
                    printf("除数不能为0, 请重新输入: ");
                    num2 = get_num();
                }
                printf("%g / %g = %g\n",
                       num1, num2, num1 / num2);
                break;
            case 'q':
            case 'Q':
                break;
            default:
                printf("请输入有效的选项!");
                break;
        }
        while (getchar()!='\n')     // 用户输入完选项后会有一个换行符,需要过滤掉
            continue;
    } while (choice != 'q');
    printf("程序已退出!");

    return 0;
}
float get_num()
{
    float f;
    char ch;
    while (scanf("%g", &f) != 1) {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" 不是一个有效的数字!\n");
        printf("请输入一个有效的数字: ");
    }

    return f;
}

void show_menu()
{
    printf("\n请输入你的选项: \n");
    printf("a. 加法                 b. 减法\n");
    printf("c. 乘法                 d. 除法\n");
    printf("q. 退出计算器小程序\n");
}