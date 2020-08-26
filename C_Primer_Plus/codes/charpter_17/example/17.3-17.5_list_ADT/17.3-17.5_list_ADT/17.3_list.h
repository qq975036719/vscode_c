// 简单链表类型头文件
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

/* 特定程序的声明 */

#define TSIZE 45
struct film
{
	char title[TSIZE];
	int rating;
};

/* 一般类型定义 */

typedef struct film Item;		// 数据域类型

typedef struct node				// 结点类型
{
	Item item;					// 数据域
	struct node* next;			// 指向下一结点
} Node;

typedef Node* List;				// 链表

/* 函数原型 */

/* 操作：						初始化一个链表*/
/* 前提条件:						plist指向一个链表*/
/* 后置条件:						链表初始化为空*/
void InitializeList(List* plist);

/* 操作:							判断链表是否为空, plist指向一个已初始化的链表*/
/* 后置条件:						若链表为空返回true, 否则返回false*/
bool ListIsEmpty(const List* plist);

/* 操作:							判断链表是否已满, plist指向一个已初始化的链表*/
/* 后置条件:						若链表已满返回true, 否则返回false*/
bool ListIsFull(const List* plist);

/* 操作:							统计链表中的项数, plist指向一个已初始化的链表*/
/* 后置条件:						返回链表中的项数*/
unsigned int ListItemCount(const List* plist);

/* 操作:							在链表末尾添加新的项*/
/* 前置条件:						item是一个待添加至链表的项, plist指向一个已初始化的链表*/
/* 后置条件:						添加成功则返回true, 失败则返回false*/
bool AddItem(Item item, List* plist);

/* 操作:							把函数作用于链表中的每一项*/
/*								plist指向一个已初始化的链表*/
/*								pfun指向一个函数, 该函数接受一个Item类型的参数, 无返回值*/
/* 后置条件:						pfun指向的函数作用于链表中的每一项一次*/
void Traverse(const List* plist, void(*pfun)(Item));

/* 操作:							释放已分配的内存*/
/* 前置条件:						plist指向一个已初始化的链表*/
/* 后置条件:						释放链表中的每一项, 链表设置为空*/
void EmptyTheList(List* plist);

#endif
