// 驱动程序 -- 用于测试多次投掷骰子并计算点数之和
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "12.12_diceroll.h"		// 头文件包含了12.11中的外部链接变量和函数

int main(void)
{
	int sides, n;
	int times;
	int status;
	int* roll_res;
	
	srand((unsigned int)time(0));	// 设置随机种子

	// 提示用户输入组数
	printf("请输入摇骰子的组数(输入q退出程序): ");

	// 骰子组数输入有效则开始主程序
	while (scanf("%d", &times) == 1 && times > 0) {
		// 提示用户输入骰子的面数和摇骰子的次数 -- 然后统计投完相应次数后的点数和
		printf("请输入骰子面数和摇骰子次数: ");

		// 判断输入的投掷次数是否有效
		if (status = scanf("%d %d", &sides, &n) != 2) {
			if (status == EOF) break;
			else {
				printf("请输入正整数!\n");
				while (getchar() != '\n') continue;		// 处理剩余的错误输入

				printf("请输入骰子面数和摇骰子次数: ");
			}
		}

		roll_res = (int*)malloc(times * sizeof(int));		// 创建一个动态分配的数组

		for (int i = 0; i < times; i++) {
			// 调用函数获取点数之和
			roll_res[i] = roll_n_dice(n, sides);
		}

		// 打印结果
		printf(" %d 组投 %d 次 %d 面骰子的点数之和结果如下: \n",
			times, n, sides);
		for (int i = 0; i < times; i++) {
			printf("%-4d", roll_res[i]);
			if ((i + 1) % 10 == 0)
				putchar('\n');
		}
		printf("\n请输入摇骰子的组数(输入q退出程序): ");
	}
	printf("程序已退出!");
}