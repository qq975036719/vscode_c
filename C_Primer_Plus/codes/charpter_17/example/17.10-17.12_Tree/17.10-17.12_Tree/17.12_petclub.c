// ʹ�ö��������
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "17.10_tree.h"

/* ����ԭ�� */
void show_menu(void);
void add_pet(Tree* ptree);
void show_pets_list(Tree* ptree);
void show_nums(Tree* ptree);
void find_pet(Tree* ptree);
void delete_pet(Tree* ptree);
void printItem(Item item);
char* s_gets(char* st, int n);
void uppercase(char* st);

// *************************************

int main(void)
{
	char ch;
	Tree pets;

	// ��ʼ��������
	InitializeTree(&pets);

	show_menu();
	ch = getchar();
	while (getchar() != '\n') continue;

	while (ch != 'q') {
		switch (ch) {
		case 'a':
			add_pet(&pets);
			break;
		case 'l':
			show_pets_list(&pets);
			break;
		case 'n':
			show_nums(&pets);
			break;
		case 'f':
			find_pet(&pets);
			break;
		case 'd':
			delete_pet(&pets);
			break;
		default:
			printf("�������ѡ���������������룡\n");
			break;
		}
		show_menu();
		ch = getchar();
		while (getchar() != '\n') continue;
	}
	DeleteAll(&pets);
	puts("Bye!");

	return 0;
}

void show_menu(void)
{
	printf("Nerfville Pet Club Membership Program\n");
	printf("Enter the letter corresponding to your choice:\n");
	printf("a) add a pet			l) show list of pets\n");
	printf("n) number of pets		f) find pets\n");
	printf("d) delete a pet			q) quit\n");
}

void add_pet(Tree* ptree)
{
	Item pet_info;

	printf("�������������");
	s_gets(pet_info.petname, SLEN);
	printf("������������ࣺ");
	s_gets(pet_info.petkind, SLEN);
	uppercase(pet_info.petname);
	uppercase(pet_info.petkind);

	if (AddItem(&pet_info, ptree))
		printf("���%s��ӳɹ���\n", pet_info.petname);
	else
		printf("���%s���ʧ�ܣ�\n", pet_info.petname);
}

void printItem(Item item)
{
	printf("��������%s			�������ࣺ%s\n", item.petname, item.petkind);
}

void show_pets_list(Tree* ptree)
{
	if (TreeIsEmpty(ptree))
		puts("û�г��");
	else {
		Traverse(ptree, printItem);
	}
}

void show_nums(Tree* ptree)
{
	printf("����������%d\n", ptree->size);
}

void find_pet(Tree* ptree)
{
	Item pet_info;

	if (TreeIsEmpty(ptree))
		puts("û�г��");
	else {
		printf("������������֣�");
		s_gets(pet_info.petname, SLEN);
		printf("������������ࣺ");
		s_gets(pet_info.petkind, SLEN);
		uppercase(pet_info.petname);
		uppercase(pet_info.petkind);

		if (InTree(pet_info, ptree))
			printf("�ó����ڳ����б���\n");
		else
			printf("�ó��ﲻ�ڳ����б���\n");
	}
}

void delete_pet(Tree* ptree)
{
	Item pet_info;

	if (TreeIsEmpty(ptree))
		printf("�����б�Ϊ�գ��޷�����ɾ��������\n");
	else {
		printf("������Ҫɾ���ĳ�������");
		s_gets(pet_info.petname, SLEN);
		printf("������ó�������ࣺ");
		s_gets(pet_info.petkind, SLEN);
		uppercase(pet_info.petname);
		uppercase(pet_info.petkind);

		if (InTree(pet_info, ptree)) {
			if (DeleteItem(&pet_info, ptree))
				printf("���%s��ɾ����\n", pet_info.petname);
			else
				printf("���%sɾ��ʧ�ܣ�\n", pet_info.petname);
		}
		else
			printf("���%s���ڳ����б��У��޷�����ɾ��������\n", pet_info.petname);
	}
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

void uppercase(char* st)
{
	while (*st) {
		*st = toupper(*st);
		st++;
	}
}