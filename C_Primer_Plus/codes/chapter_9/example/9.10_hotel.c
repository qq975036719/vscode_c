// 酒店住房价格系统的相关函数
#include <stdio.h>
#include "9.11_hotel.h"

// 展示酒店选择菜单
int menu()
{
    int code, status;
    printf("%s%s\n", STARS, STARS);
    printf("请选择你要住的酒店: \n");
    printf("1) 帝京国际大酒店           2) 天上人间乐园酒店\n");
    printf("3) 你懂得哈哈哈酒店         4) 鑫磊网咖大酒店\n");
    printf("5) 退出选择\n");
    printf("%s%s\n", STARS, STARS);

    while (status = scanf("%d", &code) != 1 ||
                    code > 5 || code < 1)
    {
        if (status != 1)
            scanf("%*s");   // 处理非整数输入
        printf("您输入的选项无效, 请输入1~5的选项: ");
    }

    return code;
}

// 获取用户输入的住房天数
int get_nights()
{
    int nights;
    printf("尊敬的用户, 您想住多少天呢: ");
    while (scanf("%d", &nights) != 1) {
        scanf("%*s");       // 处理非整数输入
        printf("请输入整数哦: ");
    }

    return nights;
}

// 用于显示住户该支付的价格
void show_price(int nights, double hotel_rate)
{
    double price = 0.0;
    double factor = 1.0;
    for (int i = 1; i <= nights; i++) {
        price += hotel_rate * factor;
        factor *= DISCOUNT;
    }
    printf("您应支付的总价格为: %g", price);
    
    return price;
}