// pe12-2b.c中要用到的函数
#include <stdio.h>
#include "pe12-2a.h"

static double kilometers;	// 用户输入的公里数 -- static表明只允许在该文件中使用该变量
static double liters;		// 用户输入的油耗(升) -- static同上
static double miles;
static double gallons;


void set_mode(int n)
{
	if (n > 1 || n < -1) {
		printf("Invalid mode specified.");
		if (mode == 0)
			printf("Mode 0(Metric) used.\n");
		else
			printf("Mode 1(US) used.\n");
	}
	else
		mode = n;
}


void get_info()
{
	switch (mode) {
		case 0:
			printf("Enter distance traveled in kilometers: ");
			scanf("%lf", &kilometers);
			while (getchar() != '\n') continue;		// 过滤多余无效输入
			printf("Enter fuel consumed in liters: ");
			scanf("%lf", &liters);
			while (getchar() != '\n') continue;		// 过滤多余无效输入
			break;
		case 1:
			printf("Enter distance traveled in miles: ");
			scanf("%lf", &miles);
			while (getchar() != '\n') continue;		// 过滤多余无效输入
			printf("Enter fuel consumed in gallons: ");
			scanf("%lf", &gallons);
			while (getchar() != '\n') continue;		// 过滤多余无效输入
			break;
		case -1:
			break;
		default:
			printf("set_mode()函数出错!");
			break;
	}
}

void show_info()
{
	switch (mode) {
		case 0:
			printf("Fuel consumption is %.2lf liters per 100km.\n",
					100 * liters / kilometers);
			break;
		case 1:
			printf("Fuel consumption is %.2lf miles per gallon.\n",
					miles / gallons);
			break;
		case -1:
			break;
		default:
			printf("set_mode()函数出错!");
	}
}