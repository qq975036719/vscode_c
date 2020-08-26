// 酒店住房价格系统 -- 总程序 -- 控制整体框架
#include <stdio.h>
#include "9.11_hotel.h"

int main(void)
{
    int nights;
    double hotel_rate = 0.0;
    int code;
    
    while ((code=menu()) != QUIT) {
        switch (code) {
            case 1:
                hotel_rate = HOTEL1;
                break;
            case 2:
                hotel_rate = HOTEL2;
                break;
            case 3:
                hotel_rate = HOTEL3;
                break;
            case 4:
                hotel_rate = HOTEL4;
                break;
            default:
                printf("没有别的酒店了哦!\n");
                break;
        }
        nights = get_nights();
        show_price(nights, hotel_rate);
    }
    printf("程序已退出!");

    return 0;
}