/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {                // 循环队列结构体
    int          *data;
    int          front;
    int          rear;
} SqQueue;

/* 功能函数 */

// 初始化一个空循环队列
void InitQueue_Sq(SqQueue *Q, int k)
{
    // 分配空间
    Q->data = (int *)malloc(sizeof(int) * k);
    Q->front = 0;
    Q->rear  = 0;
}

// 入队操作
void EnQueue_Sq(SqQueue *Q, int e, int k)
{
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % k;
}

// 出队操作
void DeQueue_Sq(SqQueue *Q, int *e, int k)
{
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % k;
}


int find_max(SqQueue Q, int k)
{
    int max = 0;

    for (int i = 0; i < k - 1; i++)
        for (int j = i + 1; j < k; j++) {
            if (Q.data[i] < Q.data[j] && max < Q.data[j])
                max = Q.data[j];
            else if (Q.data[i] >= Q.data[j] && max < Q.data[i])
                max = Q.data[i];
        }
    return max;
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int size = numsSize - k + 1;                        // 返回数组的大小
    int *res = (int *)malloc(sizeof(int) * size);       // 最终返回的数组
    SqQueue queue;                                      // 队列
    int e;

    InitQueue_Sq(&queue, k);

    // 先让nums的前k个元素依次入队
    for (int i = 0; i < k; i++)
        EnQueue_Sq(&queue, nums[i], k);

    res[0] = find_max(queue, k);

    for (int i = k, index = 1; index<size; i++, index++) {
        // 出队
        DeQueue_Sq(&queue, &e, k);
        // 入队
        EnQueue_Sq(&queue, nums[i], k);
        res[index] = find_max(queue, k);
    }

    return res;
}