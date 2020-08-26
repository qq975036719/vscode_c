// 包含了9.9_usehotel.c 和 9.10_hotel.c的所有常量和函数原型
#define QUIT 5                                      // 退出菜单的选项
#define HOTEL1 180.00                               // 酒店1的价格
#define HOTEL2 120.00                               // 酒店2的价格
#define HOTEL3 500.00                               // 酒店3的价格
#define HOTEL4 1000000.00                           // 酒店4的价格
#define STARS "******************************"      // 菜单分割线
#define DISCOUNT 0.95                               // 住多天的优惠

// 显示选择列表
int menu(void);

// 获取住房天数
int get_nights(void);

// 计算结果
void show_price(int, double);