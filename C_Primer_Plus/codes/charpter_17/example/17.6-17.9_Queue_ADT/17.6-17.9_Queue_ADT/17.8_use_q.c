// �������� -- ���Խӿں���
#include <stdio.h>
#include "17.6_queue.h"

Queue queue;
Item item;

int main(void)
{
	char ch;

	puts("���Զ��нӿں���, ����a�������");
	puts("����d��ɾ��һ����, ����q�˳�");
	
	while ((ch = getchar()) != 'q') {
		while (getchar() != '\n')
			continue;

		switch (ch) {
			case 'a':
				if (!QueueIsFull(&queue)) {
					printf("������һ������: ");
					scanf("%d", &item);
					while (getchar() != '\n') continue;
					// �����
					AddItem(item, &queue);
					// ��ӡ������Ϣ
					printf("�Ѿ���%d�������\n", item);
					printf("������������%d��\n", queue.items);
				}
				else
					puts("��������!");
				break;
			case 'd':
				if (DeleteItem(&item, &queue)) {
					printf("�ѽ�%d�Ӷ�����ɾ��\n", item);
					printf("������������%d��\n", queue.items);
				}
				else
					printf("�б�Ϊ��, �޷�ִ��ɾ������!\n");
				break;
			case 'q':
				break;
			default:
				puts("��������!");
		}
		puts("����a�����, ����dɾ�������еĵ�һ��, ����q�˳�����");
	}
	EmptyQueue(&queue);
	puts("Bye!");

	return 0;
}