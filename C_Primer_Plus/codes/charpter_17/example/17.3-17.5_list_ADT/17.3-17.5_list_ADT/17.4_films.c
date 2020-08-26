// ʹ��ADT��������
// ��17.5_list.cһ�����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "17.3_list.h"

void showmovies(Item item);
char* s_gets(char* st, int n);

List movies;
Item temp;

int main(void)
{
	/* ��ʼ�� */
	InitializeList(&movies);
	if (ListIsFull(&movies)) {
		fprintf(stderr, "��������!\n");
		exit(EXIT_FAILURE);
	}

	/* ��ʾ�û��������ݲ��洢 */
	printf("�������Ӱ����(�����˳�): ");
	while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0') {
		printf("����������: ");
		scanf("%d", &temp.rating);
		while (getchar() != '\n') continue;		// ����������

		if (AddItem(temp, &movies) == false) {
			fprintf(stderr, "�������ʧ��!\n");
			break;
		}
		if (ListIsFull(&movies)) {
			fprintf(stderr, "��������!\n");
			break;
		}
		printf("��������һ����Ӱ����(�����˳�): ");
	}

	/* ��ӡ�������� */
	if (ListIsEmpty(&movies))
		fprintf(stderr, "û�е�Ӱ��Ϣ!\n");
	else {
		puts("��Ӱ��Ϣ����:");
		Traverse(&movies, showmovies);
	}
	printf("�������� %d ����Ӱ\n", ListItemCount(&movies));

	/* �ͷ����� */
	EmptyTheList(&movies);
	puts("Bye!");

	return 0;
}

void showmovies(Item item)
{
	printf("��Ӱ����: %s -- ����: %d\n", item.title, item.rating);
}

char* s_gets(char* st, int n)
{
	char* ret_val, * find;
	
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n') continue;
	}

	return ret_val;
}