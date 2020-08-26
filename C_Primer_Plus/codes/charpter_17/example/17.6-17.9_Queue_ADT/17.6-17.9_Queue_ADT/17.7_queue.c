// 队列接口函数
#include <stdlib.h>
#include <stdio.h>
#include "17.6_queue.h"

/* 局部函数原型 -- 只在此接口函数中可见 */
static void CopyToNode(Item item, Node* pnode);		// 用在AddItem()中将Item添加到队列末尾
static void CopyToItem(Node* pnode, Item* pitem);	// 用在DeleteItem()中保存被删除的Item

// ************************************************

/* 接口函数定义 */
// 初始化队列 -- 指向首尾项的指针设置为NULL -- 项数为0
void InitializeQueue(Queue* pq)
{
	pq->front = pq->last = NULL;
	pq->items = 0;
}

// 判断队列是否为空
bool QueueIsEmpty(const Queue* pq)
{
	return (pq->items == 0);
}

// 判断队列是否已满
bool QueueIsFull(const Queue* pq)
{
	return (pq->items == MAXQUEUE);
}

// 统计队列的项数
unsigned int QueueItemCount(const Queue* pq)
{
	return pq->items;
}

// 在队列末尾添加项
bool AddItem(Item item, Queue* pq)
{
	// 判断队列是否已满
	if (QueueIsFull(pq))
		return false;

	Node* pnew = (Node*)malloc(sizeof(Node));
	// 判断分配内存是否成功
	if (pnew == NULL) {
		fprintf(stderr, "无法分配内存!\n");
		exit(EXIT_FAILURE);
	}

	// 将待添加项拷贝到新结点
	CopyToNode(item, pnew);
	// 新结点的next指向NULL表示新结点为最后一个结点
	pnew->next = NULL;

	// 如果队列添加前为空 -- 则新结点是首项也是尾项
	if (QueueIsEmpty(pq))
		pq->front = pnew;
	else
		pq->last->next = pnew;		// 让pnew成为原本最后一个结点的下一个结点
	pq->last = pnew;				// 让last指向pnew -- 意味着pnew成为了最后一个结点
	/* pq->last->next = pnew -- 只是把pnew放进队列的末尾, 此时pnew在队列中是最后一个结点*/
	/* 但是pq->last还指向着添加pnew结点的前一个结点, 也就是说此时实际上的最后一个结点不是pnew*/
	/* 所以要用pq->last = pnew来使last指向pnew来表明pnew是最后一个结点*/

	// 项数加1
	pq->items++;

	return true;
}

// 删除队列中的第一项
bool DeleteItem(Item* pitem, Queue* pq)
{
	// 空队列无法删除项 -- 返回false
	if (QueueIsEmpty(pq))
		return false;

	Node* temp;
	/* 指向Node的temp指针存在的意义 -- 因为要让front指向下一个结点*/
	/* 指向下一个结点后free的时候就不知道该free谁了, 用temp保存第一个结点的地址*/
	/* 这样就可以free(temp)来释放第一个结点 -- 即删除第一个结点*/

	CopyToItem(pq->front, pitem);	// 将被删除的项拷贝到item中
	temp = pq->front;				// 将第一个结点临时存储到temp中
	pq->front = pq->front->next;	// 让front指向被删除结点的下一个结点
	free(temp);						// 删除第一个结点(释放)
	
	// 项数-1
	pq->items--;

	// 如果删除后队列为空 -- 则指向首项和尾项的两个指针都为NULL
	if (pq->items == 0)
		pq->last = NULL;
	/* 这里不写成pq->front = pq->last = NULL*/
	/* 因为如果删除第一项后队列为空(项数==0), 则原本队列只有一项*/
	/* 因为前面有pq->front = pq->front->next -- 这里的next指向NULL*/
	
	return true;
}

// 清空队列
void EmptyQueue(Queue* pq)
{
	Item dummy;

	while (!QueueIsEmpty(pq))
		DeleteItem(&dummy, pq);
	/* 用DeleteItem()函数来不断删除队列的第一项 -- 直到队列为空则达到了清空队列的目的*/
}

// ************************************************
/* 局部函数定义 */
static void CopyToNode(Item item, Node* pnode)
{
	pnode->item = item;
}

static void CopyToItem(Node* pnode, Item* pitem)
{
	*pitem = pnode->item;
}