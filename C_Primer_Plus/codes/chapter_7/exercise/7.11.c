// 杂货店订单处理程序
#include <stdio.h>
#define APPLE 2.05          // 苹果价格(美金/磅)
#define SUGAR_BEET 1.15     // 甜菜价格(美金/磅)
#define CARROT 1.09         // 胡萝卜价格(美金/磅)
#define DISCOUNT 0.05       // 订单满100美元的优惠折扣

int main(void)
{
    // 声明需要用到的变量
    float apple = 0.0;          // 单次输入苹果的数量
    float sugar_beet = 0.0;     // 单次输入甜菜的数量
    float carrot = 0.0;         // 单次输入胡萝卜的数量
    float total_a = 0.0;        // 苹果总重量
    float total_b = 0.0;        // 甜菜总重量
    float total_c = 0.0;        // 胡萝卜总重量
    char type;                  // 用户输入的选择
    float price;                // 订单价格
    float freight;              // 运费和包装费

    // 声明需要用到的函数原型
    void show_menu();                                   // 显示购买菜单
    float calc_price(float a, float b, float c);        // 计算订单价格
    float calc_freight(float a, float b, float c);      // 计算运费和包装费

    do {        // 此循环用于统计购买的数量
        // 提示用户输入购买信息
        show_menu();
        scanf("%c", &type);
        
        // 分类处理订单情况
        switch (type) {
            case 'a':                           // 选择购买苹果的情况
                printf("请输入购买磅数: ");
                scanf("%f", &apple);
                total_a += apple;
                printf("已向购物车中添加了%.2f磅苹果！\n", apple);
                getchar();                      // 将输入重量后的换行符读取掉
                break;
            case 'b':                           // 选择购买甜菜的情况
                printf("请输入购买磅数: ");
                scanf("%f", &sugar_beet);
                total_b += sugar_beet;
                printf("已向购物车中添加了%.2f磅甜菜！\n", sugar_beet);
                getchar();                      // 将输入重量后的换行符读取掉
                break;
            case 'c':                           // 选择购买胡萝卜的情况
                printf("请输入购买磅数: ");
                scanf("%f", &carrot);
                total_c += carrot;
                printf("已向购物车中添加了%.2f磅胡萝卜！\n", carrot);
                getchar();                      // 将输入重量后的换行符读取掉
                break;
            case 'q':
                break;
            default:
                printf("请输入有效的选项(a, b, c, q)！！！\n");
                getchar();
                break;
        }
    } while (type != 'q');
    
    // 计算订单价格
    price = calc_price(total_a, total_b, total_c);
    // 计算运费和包装费
    freight = calc_freight(total_a, total_b, total_c);
    
    // 打印订单信息
    printf("苹果的价格为$%.2f每磅, 甜菜的价格为$%.2f每磅, 胡萝卜的价格为$%.2f每磅\n\n",
           APPLE, SUGAR_BEET, CARROT);
    printf("您购买的商品有: 苹果 %.2f 磅, 甜菜 %.2f 磅, 胡萝卜 %.2f 磅\n\n",
           total_a, total_b, total_c);
    printf("总重量为: %.2f\n\n",
           total_a + total_b + total_c);
    printf("订单价格为: %.2f\n\n", price);
    // 如果订单满100美金,计算折扣价并打印
    if (price>=100) {
        printf("订单优惠金额: %.2f\n\n",
               price * DISCOUNT);
        printf("实际订单价格为: %.2f\n\n",
               price * (1 - DISCOUNT));
        printf("运费和包装费为: %.2f\n\n", freight);
        printf("此次购物的总费用为: %.2f\n\n",
               price * (1 - DISCOUNT) + freight);
    }
    // 订单不满100美金,无折扣
    else {
        printf("运费和包装费为: %.2f\n\n", freight);
        printf("此次购物的总费用为: %.2f\n\n",
               price + freight);
    }
}
// 函数定义部分
void show_menu()
{
    printf("************************************************************\n");
    printf("请选择购买的种类: \n");
    printf("a) 苹果\t\tb) 甜菜\n");
    printf("c) 胡萝卜\tq) 退出并计算价格\n");
    printf("************************************************************\n");
}
float calc_price(float a, float b, float c)
{
    float price = 0.0;
    price = a * APPLE + b * SUGAR_BEET + c * CARROT;
    return price;
}
float calc_freight(float a, float b, float c)
{
    float freight = 0.0;            // 运费和包装费
    float total = a + b + c;        // 总重量

    if (total > 0 && total <= 5)    // 重量0-5时
        freight = 6.5;
    if (total >5&&total <=20)       // 重量5-20时
        freight = 14.0;
    if (total>20)                   // 重量超过20磅时
        freight = 14 + (total - 20) * 0.5;

    return freight;
}