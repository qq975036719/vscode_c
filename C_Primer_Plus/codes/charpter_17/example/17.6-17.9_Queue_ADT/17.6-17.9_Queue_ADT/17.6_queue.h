// 队列头文件
#ifndef QUEUE_H_
#define QUEUE_H_
#define MAXQUEUE 3
#include <stdbool.h>

// ************************************************
/* 定义数据类型 */
//typedef int Item;		// 项
typedef struct item {
	long arrive;		// 顾客加入队列时的时间
	int processtime;	// 该顾客咨询时花费的时间
} Item;

typedef struct node {	// 结点
	Item item;
	struct node* next;
} Node;

typedef struct queue {	// 队列
	Node* front;		// 指向队列首项
	Node* last;			// 指向队列尾项
	unsigned int items;	// 项数
} Queue;

// ************************************************

// 函数原型

/* 操作:					初始化队列 */	
/* 前置条件:				pq指向一个队列 */
/* 后置条件:				初始化得到一个空队列 */
void InitializeQueue(Queue* pq);

/* 操作:					判断队列是否为空 */
/* 前置条件:				pq指向一个已初始化的队列 */
/* 后置条件:				为空返回true */
bool QueueIsEmpty(const Queue* pq);

/* 操作:					判断队列是否已满 */
/* 前置条件:				pq指向一个已初始化的队列 */
/* 后置条件:				已满返回true */
bool QueueIsFull(const Queue* pq);

/* 操作:					统计队列中的项数 */
/* 前置条件:				pq指向一个已初始化的队列 */
/* 后置条件:				返回队列中的项数 */
unsigned int QueueItemCount(const Queue* pq);

/* 操作:					在队列末尾添加新的项 */
/* 前置条件:				item是待添加项 ,pq指向一个已初始化队列 */
/* 后置条件:				队列不为空, 添加item到末尾, 返回true */
/*						否则保持队列不变, 返回false*/

bool AddItem(Item item, Queue* pq);

/* 操作:					删除队列中的第一项 */
/* 前置条件:				item用于存储被删除项 ,pq指向一个已初始化的队列 */
/* 后置条件:				如果队列删除前不为空, 则返回第一个项并删除该项, 返回true */
/*						如果队列删除前为不为空, 删除第一项后为空, 则重置队列为空, 返回true*/
/*						如果队列删除前为空, 则返回false*/
bool DeleteItem(Item* item, Queue* pq);

/* 操作:					清空队列 */
/* 前置条件:				pq指向一个已初始化的队列 */
/* 后置条件:				队列被清空 */
void EmptyQueue(Queue* pq);

#endif