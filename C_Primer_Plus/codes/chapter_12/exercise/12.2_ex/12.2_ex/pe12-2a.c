// pe12-2b.c��Ҫ�õ��ĺ���
#include <stdio.h>
#include "pe12-2a.h"

static double kilometers;	// �û�����Ĺ����� -- static����ֻ�����ڸ��ļ���ʹ�øñ���
static double liters;		// �û�������ͺ�(��) -- staticͬ��
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
			while (getchar() != '\n') continue;		// ���˶�����Ч����
			printf("Enter fuel consumed in liters: ");
			scanf("%lf", &liters);
			while (getchar() != '\n') continue;		// ���˶�����Ч����
			break;
		case 1:
			printf("Enter distance traveled in miles: ");
			scanf("%lf", &miles);
			while (getchar() != '\n') continue;		// ���˶�����Ч����
			printf("Enter fuel consumed in gallons: ");
			scanf("%lf", &gallons);
			while (getchar() != '\n') continue;		// ���˶�����Ч����
			break;
		case -1:
			break;
		default:
			printf("set_mode()��������!");
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
			printf("set_mode()��������!");
	}
}