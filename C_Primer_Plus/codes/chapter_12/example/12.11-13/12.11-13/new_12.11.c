// ������ģ�����

#include <stdio.h>
#include <stdio.h>		// �ṩrand()������ԭ��
#include "12.12_diceroll.h"

// ��õ���Ͷ�����ӵĵ��� -- ��Ϊroll_n_dice()�����ĸ������� -- ����Ϊstatic����
static int rolldice(int sides)
{
	int roll;

	roll = rand() % sides + 1;

	return roll;
}

// Ͷ��n�����Ӳ�����ÿ��Ͷ���ĵ���֮��
int roll_n_dice(int n, int sides)	// n��Ͷ�����ӵĴ��� -- sides�����ӵ�����
{
	int total = 0;
	
	// �ж���������������Ƿ���Ч
	if (sides < 2) {
		printf("���ӵ��������ܵ���2(����Ϊ2ʱ��Ӳ��)!\n");
		return -2;
	}

	// �ж������Ͷ�������Ƿ���Ч
	if (n < 1) {
		printf("Ͷ���Ĵ���������1��!\n");
		return -1;
	}

	// ����Ͷ���������ܺ�
	for (int i = 0; i < n; i++)
		total += rolldice(sides);

	return total;
}