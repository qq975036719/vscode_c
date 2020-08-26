// ����ͷ�ļ�
#ifndef QUEUE_H_
#define QUEUE_H_
#define MAXQUEUE 3
#include <stdbool.h>

// ************************************************
/* ������������ */
//typedef int Item;		// ��
typedef struct item {
	long arrive;		// �˿ͼ������ʱ��ʱ��
	int processtime;	// �ù˿���ѯʱ���ѵ�ʱ��
} Item;

typedef struct node {	// ���
	Item item;
	struct node* next;
} Node;

typedef struct queue {	// ����
	Node* front;		// ָ���������
	Node* last;			// ָ�����β��
	unsigned int items;	// ����
} Queue;

// ************************************************

// ����ԭ��

/* ����:					��ʼ������ */	
/* ǰ������:				pqָ��һ������ */
/* ��������:				��ʼ���õ�һ���ն��� */
void InitializeQueue(Queue* pq);

/* ����:					�ж϶����Ƿ�Ϊ�� */
/* ǰ������:				pqָ��һ���ѳ�ʼ���Ķ��� */
/* ��������:				Ϊ�շ���true */
bool QueueIsEmpty(const Queue* pq);

/* ����:					�ж϶����Ƿ����� */
/* ǰ������:				pqָ��һ���ѳ�ʼ���Ķ��� */
/* ��������:				��������true */
bool QueueIsFull(const Queue* pq);

/* ����:					ͳ�ƶ����е����� */
/* ǰ������:				pqָ��һ���ѳ�ʼ���Ķ��� */
/* ��������:				���ض����е����� */
unsigned int QueueItemCount(const Queue* pq);

/* ����:					�ڶ���ĩβ����µ��� */
/* ǰ������:				item�Ǵ������ ,pqָ��һ���ѳ�ʼ������ */
/* ��������:				���в�Ϊ��, ���item��ĩβ, ����true */
/*						���򱣳ֶ��в���, ����false*/

bool AddItem(Item item, Queue* pq);

/* ����:					ɾ�������еĵ�һ�� */
/* ǰ������:				item���ڴ洢��ɾ���� ,pqָ��һ���ѳ�ʼ���Ķ��� */
/* ��������:				�������ɾ��ǰ��Ϊ��, �򷵻ص�һ���ɾ������, ����true */
/*						�������ɾ��ǰΪ��Ϊ��, ɾ����һ���Ϊ��, �����ö���Ϊ��, ����true*/
/*						�������ɾ��ǰΪ��, �򷵻�false*/
bool DeleteItem(Item* item, Queue* pq);

/* ����:					��ն��� */
/* ǰ������:				pqָ��һ���ѳ�ʼ���Ķ��� */
/* ��������:				���б���� */
void EmptyQueue(Queue* pq);

#endif