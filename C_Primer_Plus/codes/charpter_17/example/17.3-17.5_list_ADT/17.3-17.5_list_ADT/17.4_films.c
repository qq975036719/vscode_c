// 使用ADT风格的链表
// 与17.5_list.c一起编译
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
	/* 初始化 */
	InitializeList(&movies);
	if (ListIsFull(&movies)) {
		fprintf(stderr, "链表满了!\n");
		exit(EXIT_FAILURE);
	}

	/* 提示用户输入数据并存储 */
	printf("请输入电影名称(空行退出): ");
	while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0') {
		printf("请输入评分: ");
		scanf("%d", &temp.rating);
		while (getchar() != '\n') continue;		// 清理输入行

		if (AddItem(temp, &movies) == false) {
			fprintf(stderr, "添加数据失败!\n");
			break;
		}
		if (ListIsFull(&movies)) {
			fprintf(stderr, "链表满了!\n");
			break;
		}
		printf("请输入下一部电影名称(空行退出): ");
	}

	/* 打印链表内容 */
	if (ListIsEmpty(&movies))
		fprintf(stderr, "没有电影信息!\n");
	else {
		puts("电影信息如下:");
		Traverse(&movies, showmovies);
	}
	printf("你输入了 %d 部电影\n", ListItemCount(&movies));

	/* 释放链表 */
	EmptyTheList(&movies);
	puts("Bye!");

	return 0;
}

void showmovies(Item item)
{
	printf("电影名称: %s -- 评分: %d\n", item.title, item.rating);
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