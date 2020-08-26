// 掷骰子模拟程序

#include <stdio.h>
#include <stdio.h>		// 提供rand()函数的原型
#include "12.12_diceroll.h"

// 获得单次投掷骰子的点数 -- 作为roll_n_dice()函数的辅助函数 -- 声明为static函数
static int rolldice(int sides)
{
	int roll;

	roll = rand() % sides + 1;

	return roll;
}

// 投掷n次骰子并计算每次投掷的点数之和
int roll_n_dice(int n, int sides)	// n是投掷骰子的次数 -- sides是骰子的面数
{
	int total = 0;
	
	// 判断输入的骰子面数是否有效
	if (sides < 2) {
		printf("骰子的面数不能低于2(面数为2时是硬币)!\n");
		return -2;
	}

	// 判断输入的投掷次数是否有效
	if (n < 1) {
		printf("投掷的次数至少是1次!\n");
		return -1;
	}

	// 计算投掷点数的总和
	for (int i = 0; i < n; i++)
		total += rolldice(sides);

	return total;
}