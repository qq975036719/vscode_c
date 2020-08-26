#include <stdio.h>
#include <stdlib.h>
#include "17.3_list.h"

/* �ֲ�����ԭ�� */
static void CopyToNode(Item item, Node* pnode);

/* �ӿں��� */

/* ��ʼ������Ϊ�� */
void InitializeList(List* plist)
{
	plist = NULL;
}

/* �ж������Ƿ�Ϊ�� */
bool ListIsEmpty(const List* plist)
{
	if (*plist == NULL)
		return true;
	else
		return false;
}

/* �ж������Ƿ����� */
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

/* ͳ���������� */
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

/* ���һ���µĽ�㵽����ĩβ */
bool AddItem(Item item, List* plist)
{
	Node* pnew;
	Node* scan = *plist;

	pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;
	
	// ������item��ӵ��½����
	CopyToNode(item, pnew);
	pnew->next = NULL;		// �½����Ϊ���һ����� -- nextָ��NULL
	// ���½����ӵ�������
	
    // �ж������Ƿ�Ϊ�� -- Ϊ�����½����Ϊ��һ�����
	if (scan == NULL)
		*plist = pnew;
	// ��Ϊ����Ѱ������Ľ�β
	else {
		while (scan->next != NULL)
			scan = scan->next;
		scan->next = pnew;
	}

	return true;
}

/* ����ÿ����㲢ִ��pfunָ��ĺ��� */
void Traverse(const List* plist, void(*pfun)(Item))
{
	Node* pnode = *plist;

	while (pnode != NULL) {
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

/* �ͷ����� */
void EmptyTheList(List* plist)
{
	Node* psave = *plist;

	while (psave != NULL) {
		psave = (*plist)->next;
		free(*plist);
		*plist = psave;
	}
}

/* �ֲ��������� */
// ��һ������������
static void CopyToNode(Item item, Node* pnode)
{
	pnode->item = item;
}