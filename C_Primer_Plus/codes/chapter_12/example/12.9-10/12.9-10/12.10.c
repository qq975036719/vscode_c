// �������� -- ����rand1()��srand1()����
#include <stdio.h>

extern int rand1(void);
extern void srand1(unsigned int seed);

int main(void)
{
	int count = 0;
	unsigned int seed;

	printf("������һ��������Ϊ����: ");
	while (scanf("%u", &seed) == 1) {
		srand1(seed);	// �������ӣ����ɲ�ͬ�����������
		for (count = 0; count < 5; count++)
			printf("%d\n", rand1());
		printf("������һ��������Ϊ����: ");
	}
	printf("�������˳�!");

	return 0;
}