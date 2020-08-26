// ����������ͷ�ļ�
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

/* �ض���������� */

#define TSIZE 45
struct film
{
	char title[TSIZE];
	int rating;
};

/* һ�����Ͷ��� */

typedef struct film Item;		// ����������

typedef struct node				// �������
{
	Item item;					// ������
	struct node* next;			// ָ����һ���
} Node;

typedef Node* List;				// ����

/* ����ԭ�� */

/* ������						��ʼ��һ������*/
/* ǰ������:						plistָ��һ������*/
/* ��������:						�����ʼ��Ϊ��*/
void InitializeList(List* plist);

/* ����:							�ж������Ƿ�Ϊ��, plistָ��һ���ѳ�ʼ��������*/
/* ��������:						������Ϊ�շ���true, ���򷵻�false*/
bool ListIsEmpty(const List* plist);

/* ����:							�ж������Ƿ�����, plistָ��һ���ѳ�ʼ��������*/
/* ��������:						��������������true, ���򷵻�false*/
bool ListIsFull(const List* plist);

/* ����:							ͳ�������е�����, plistָ��һ���ѳ�ʼ��������*/
/* ��������:						���������е�����*/
unsigned int ListItemCount(const List* plist);

/* ����:							������ĩβ����µ���*/
/* ǰ������:						item��һ����������������, plistָ��һ���ѳ�ʼ��������*/
/* ��������:						��ӳɹ��򷵻�true, ʧ���򷵻�false*/
bool AddItem(Item item, List* plist);

/* ����:							�Ѻ��������������е�ÿһ��*/
/*								plistָ��һ���ѳ�ʼ��������*/
/*								pfunָ��һ������, �ú�������һ��Item���͵Ĳ���, �޷���ֵ*/
/* ��������:						pfunָ��ĺ��������������е�ÿһ��һ��*/
void Traverse(const List* plist, void(*pfun)(Item));

/* ����:							�ͷ��ѷ�����ڴ�*/
/* ǰ������:						plistָ��һ���ѳ�ʼ��������*/
/* ��������:						�ͷ������е�ÿһ��, ��������Ϊ��*/
void EmptyTheList(List* plist);

#endif
