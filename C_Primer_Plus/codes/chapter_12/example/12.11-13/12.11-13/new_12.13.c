// �������� -- ���ڲ��Զ��Ͷ�����Ӳ��������֮��
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "12.12_diceroll.h"		// ͷ�ļ�������12.11�е��ⲿ���ӱ����ͺ���

int main(void)
{
	int sides, n;
	int times;
	int status;
	int* roll_res;
	
	srand((unsigned int)time(0));	// �����������

	// ��ʾ�û���������
	printf("������ҡ���ӵ�����(����q�˳�����): ");

	// ��������������Ч��ʼ������
	while (scanf("%d", &times) == 1 && times > 0) {
		// ��ʾ�û��������ӵ�������ҡ���ӵĴ��� -- Ȼ��ͳ��Ͷ����Ӧ������ĵ�����
		printf("����������������ҡ���Ӵ���: ");

		// �ж������Ͷ�������Ƿ���Ч
		if (status = scanf("%d %d", &sides, &n) != 2) {
			if (status == EOF) break;
			else {
				printf("������������!\n");
				while (getchar() != '\n') continue;		// ����ʣ��Ĵ�������

				printf("����������������ҡ���Ӵ���: ");
			}
		}

		roll_res = (int*)malloc(times * sizeof(int));		// ����һ����̬���������

		for (int i = 0; i < times; i++) {
			// ���ú�����ȡ����֮��
			roll_res[i] = roll_n_dice(n, sides);
		}

		// ��ӡ���
		printf(" %d ��Ͷ %d �� %d �����ӵĵ���֮�ͽ������: \n",
			times, n, sides);
		for (int i = 0; i < times; i++) {
			printf("%-4d", roll_res[i]);
			if ((i + 1) % 10 == 0)
				putchar('\n');
		}
		printf("\n������ҡ���ӵ�����(����q�˳�����): ");
	}
	printf("�������˳�!");
}