// ��ʾ��ͬ�Ĵ洢���
#include <stdio.h>

void report_count();
void accumulate(int k);

int count = 0;		// �ļ��������ⲿ���ӡ���̬�洢��

int main(void)
{
	int value;		// �Զ�����
	register int i;	// �Ĵ�������

	printf("������һ��������(����0�˳�����): ");
	while (scanf("%d", &value) == 1 && value > 0) {
		++count;	// ʹ���ļ����������(ȫ�ֱ���)
		for (i = value; i >= 0; i--)
			accumulate(i);
		printf("������һ��������(����0�˳�����): ");
	}
	report_count();

	return 0;
}

void report_count()
{
	printf("ѭ��ִ����%d��", count);
}