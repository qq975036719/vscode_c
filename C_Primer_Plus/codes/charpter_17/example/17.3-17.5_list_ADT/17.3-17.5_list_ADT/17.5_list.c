#include <stdio.h>
#include <stdlib.h>
#include "17.3_list.h"

/* 局部函数原型 */
static void CopyToNode(Item item, Node* pnode);

/* 接口函数 */

/* 初始化链表为空 */
void InitializeList(List* plist)
{
	plist = NULL;
}

/* 判断链表是否为空 */
bool ListIsEmpty(const List* plist)
{
	if (*plist == NULL)
		return true;
	else
		return false;
}

/* 判断链表是否已满 */
bool ListIsFull(const List* plist)
{
	Node* ptemp = (Node*)malloc(sizeof(Node));
	bool full;

	if (ptemp == NULL)
		full = true;
	else
		full = false;
	free(ptemp);
	
	return full;
}

/* 统计链表项数 */
unsigned int ListItemCount(const List* plist)
{
	unsigned int ct = 0;
	Node* pnode = *plist;

	while (pnode != NULL) {
		ct++;
		pnode = pnode->next;
	}

	return ct;
}

/* 添加一个新的结点到链表末尾 */
bool AddItem(Item item, List* plist)
{
	Node* pnew;
	Node* scan = *plist;

	pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;
	
	// 将数据item添加到新结点中
	CopyToNode(item, pnew);
	pnew->next = NULL;		// 新结点作为最后一个结点 -- next指向NULL
	// 将新结点添加到链表中
	
    // 判断链表是否为空 -- 为空则新结点作为第一个结点
	if (scan == NULL)
		*plist = pnew;
	// 不为空则寻找链表的结尾
	else {
		while (scan->next != NULL)
			scan = scan->next;
		scan->next = pnew;
	}

	return true;
}

/* 访问每个结点并执行pfun指向的函数 */
void Traverse(const List* plist, void(*pfun)(Item))
{
	Node* pnode = *plist;

	while (pnode != NULL) {
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

/* 释放链表 */
void EmptyTheList(List* plist)
{
	Node* psave = *plist;

	while (psave != NULL) {
		psave = (*plist)->next;
		free(*plist);
		*plist = psave;
	}
}

/* 局部函数定义 */
// 把一个项拷贝到结点中
static void CopyToNode(Item item, Node* pnode)
{
	pnode->item = item;
}