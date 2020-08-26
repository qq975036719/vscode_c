// 使用二叉查找树
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "17.10_tree.h"

/* 函数原型 */
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

	// 初始化二叉树
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
			printf("你输入的选项有误，请重新输入！\n");
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

	printf("请输入宠物名：");
	s_gets(pet_info.petname, SLEN);
	printf("请输入宠物种类：");
	s_gets(pet_info.petkind, SLEN);
	uppercase(pet_info.petname);
	uppercase(pet_info.petkind);

	if (AddItem(&pet_info, ptree))
		printf("宠物：%s添加成功！\n", pet_info.petname);
	else
		printf("宠物：%s添加失败！\n", pet_info.petname);
}

void printItem(Item item)
{
	printf("宠物名：%s			宠物种类：%s\n", item.petname, item.petkind);
}

void show_pets_list(Tree* ptree)
{
	if (TreeIsEmpty(ptree))
		puts("没有宠物！");
	else {
		Traverse(ptree, printItem);
	}
}

void show_nums(Tree* ptree)
{
	printf("宠物数量：%d\n", ptree->size);
}

void find_pet(Tree* ptree)
{
	Item pet_info;

	if (TreeIsEmpty(ptree))
		puts("没有宠物！");
	else {
		printf("请输入宠物名字：");
		s_gets(pet_info.petname, SLEN);
		printf("请输入宠物种类：");
		s_gets(pet_info.petkind, SLEN);
		uppercase(pet_info.petname);
		uppercase(pet_info.petkind);

		if (InTree(pet_info, ptree))
			printf("该宠物在宠物列表中\n");
		else
			printf("该宠物不在宠物列表中\n");
	}
}

void delete_pet(Tree* ptree)
{
	Item pet_info;

	if (TreeIsEmpty(ptree))
		printf("宠物列表为空，无法进行删除操作！\n");
	else {
		printf("请输入要删除的宠物名：");
		s_gets(pet_info.petname, SLEN);
		printf("请输入该宠物的种类：");
		s_gets(pet_info.petkind, SLEN);
		uppercase(pet_info.petname);
		uppercase(pet_info.petkind);

		if (InTree(pet_info, ptree)) {
			if (DeleteItem(&pet_info, ptree))
				printf("宠物：%s已删除！\n", pet_info.petname);
			else
				printf("宠物：%s删除失败！\n", pet_info.petname);
		}
		else
			printf("宠物：%s不在宠物列表中，无法进行删除操作！\n", pet_info.petname);
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