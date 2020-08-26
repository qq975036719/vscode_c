// ���нӿں���
#include <stdlib.h>
#include <stdio.h>
#include "17.6_queue.h"

/* �ֲ�����ԭ�� -- ֻ�ڴ˽ӿں����пɼ� */
static void CopyToNode(Item item, Node* pnode);		// ����AddItem()�н�Item��ӵ�����ĩβ
static void CopyToItem(Node* pnode, Item* pitem);	// ����DeleteItem()�б��汻ɾ����Item

// ************************************************

/* �ӿں������� */
// ��ʼ������ -- ָ����β���ָ������ΪNULL -- ����Ϊ0
void InitializeQueue(Queue* pq)
{
	pq->front = pq->last = NULL;
	pq->items = 0;
}

// �ж϶����Ƿ�Ϊ��
bool QueueIsEmpty(const Queue* pq)
{
	return (pq->items == 0);
}

// �ж϶����Ƿ�����
bool QueueIsFull(const Queue* pq)
{
	return (pq->items == MAXQUEUE);
}

// ͳ�ƶ��е�����
unsigned int QueueItemCount(const Queue* pq)
{
	return pq->items;
}

// �ڶ���ĩβ�����
bool AddItem(Item item, Queue* pq)
{
	// �ж϶����Ƿ�����
	if (QueueIsFull(pq))
		return false;

	Node* pnew = (Node*)malloc(sizeof(Node));
	// �жϷ����ڴ��Ƿ�ɹ�
	if (pnew == NULL) {
		fprintf(stderr, "�޷������ڴ�!\n");
		exit(EXIT_FAILURE);
	}

	// �������������½��
	CopyToNode(item, pnew);
	// �½���nextָ��NULL��ʾ�½��Ϊ���һ�����
	pnew->next = NULL;

	// ����������ǰΪ�� -- ���½��������Ҳ��β��
	if (QueueIsEmpty(pq))
		pq->front = pnew;
	else
		pq->last->next = pnew;		// ��pnew��Ϊԭ�����һ��������һ�����
	pq->last = pnew;				// ��lastָ��pnew -- ��ζ��pnew��Ϊ�����һ�����
	/* pq->last->next = pnew -- ֻ�ǰ�pnew�Ž����е�ĩβ, ��ʱpnew�ڶ����������һ�����*/
	/* ����pq->last��ָ�������pnew����ǰһ�����, Ҳ����˵��ʱʵ���ϵ����һ����㲻��pnew*/
	/* ����Ҫ��pq->last = pnew��ʹlastָ��pnew������pnew�����һ�����*/

	// ������1
	pq->items++;

	return true;
}

// ɾ�������еĵ�һ��
bool DeleteItem(Item* pitem, Queue* pq)
{
	// �ն����޷�ɾ���� -- ����false
	if (QueueIsEmpty(pq))
		return false;

	Node* temp;
	/* ָ��Node��tempָ����ڵ����� -- ��ΪҪ��frontָ����һ�����*/
	/* ָ����һ������free��ʱ��Ͳ�֪����free˭��, ��temp�����һ�����ĵ�ַ*/
	/* �����Ϳ���free(temp)���ͷŵ�һ����� -- ��ɾ����һ�����*/

	CopyToItem(pq->front, pitem);	// ����ɾ���������item��
	temp = pq->front;				// ����һ�������ʱ�洢��temp��
	pq->front = pq->front->next;	// ��frontָ��ɾ��������һ�����
	free(temp);						// ɾ����һ�����(�ͷ�)
	
	// ����-1
	pq->items--;

	// ���ɾ�������Ϊ�� -- ��ָ�������β�������ָ�붼ΪNULL
	if (pq->items == 0)
		pq->last = NULL;
	/* ���ﲻд��pq->front = pq->last = NULL*/
	/* ��Ϊ���ɾ����һ������Ϊ��(����==0), ��ԭ������ֻ��һ��*/
	/* ��Ϊǰ����pq->front = pq->front->next -- �����nextָ��NULL*/
	
	return true;
}

// ��ն���
void EmptyQueue(Queue* pq)
{
	Item dummy;

	while (!QueueIsEmpty(pq))
		DeleteItem(&dummy, pq);
	/* ��DeleteItem()����������ɾ�����еĵ�һ�� -- ֱ������Ϊ����ﵽ����ն��е�Ŀ��*/
}

// ************************************************
/* �ֲ��������� */
static void CopyToNode(Item item, Node* pnode)
{
	pnode->item = item;
}

static void CopyToItem(Node* pnode, Item* pitem)
{
	*pitem = pnode->item;
}