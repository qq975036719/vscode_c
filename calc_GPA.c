// 计算学分绩点的计算器交互小程序
#include <stdio.h>
#define CREDIT_SIZE 30
#define GPA_SIZE 30

void show_menu();                                           // 打印菜单
void show_format();                                         // 打印格式信息
double calc_GPA(double *credit, double *gpa, int n);        // 计算GPA

int main(void)
{
    int ct_gpa;                         // 待计算的科目数量
    double credit[CREDIT_SIZE];         // 学分数组 -- 用于存储用户输入的学分
    double gpa[GPA_SIZE];               // 绩点数组 -- 用于存储用户输入的绩点
    double res_gpa;                     // 用户的最终gpa计算结果

    while (1) {
        // 打印提示信息
        show_menu();
        printf("请输入待计算的科目数量: ");

        // 判断用户输入的是否是整数
        while (scanf("%d", &ct_gpa) != 1) {
            printf("请输入一个整数(科目数量只可能是整数)!\n");
            while (getchar()!='\n')
                continue;
        }

        // 打印格式信息
        show_format();

        // 存储用户输入的学分和绩点
        for (int i = 0; i < ct_gpa; i++) {
            scanf("%lf", &credit[i]);
            scanf("%lf", &gpa[i]);
            while (getchar()!='\n')
                continue;
        }

        // 计算用户的GPA
        res_gpa = calc_GPA(credit, gpa, ct_gpa);

        // 打印用户的GPA
        printf("根据你输入的数据,你的预期GPA = %g\n\n\n\n\n", res_gpa);
    }

    return 0;
}

void show_menu()
{
    printf("*********************************************\n");
    printf("            欢迎使用绩点计算小程序!\n");
    printf("            开发者: 草帽Plasticine\n");
    printf("*********************************************\n");
}

void show_format()
{
    printf("请按如下格式输入你所查询的学科的学分和你的学科绩点: \n");
    printf("学科学分     学科绩点\n");
    printf("   2           3.5\n");
    printf("   3           3.8\n");
    printf("   3           4.0\n");
    printf("不一定是输入三个,输入的数量取决于你刚开始输入的待查询学科数量\n");
    printf("格式:先输入科目的学分然后空格再输入学科的绩点,输入完一组之后换行输入下一组即可\n");
}

double calc_GPA(double *credit, double *gpa, int n)
{
    double credit_sum = 0;    // 存储总学分
    double res_gpa = 0;       // 存储gpa          

    // 计算总学分
    for (int i = 0; i < n; i++)
        credit_sum += credit[i];

    // 计算绩点
    for (int j = 0; j < n; j++)
        res_gpa += (credit[j] / credit_sum) * gpa[j];

    return res_gpa;
}