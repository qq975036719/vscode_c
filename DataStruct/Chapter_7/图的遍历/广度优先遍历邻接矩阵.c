// 广度优先遍历邻接矩阵(BFS)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 邻接矩阵结构定义
typedef char ElemType;
typedef int EdgeType;
#define MAX_VEX 100

typedef struct {
    ElemType vex[MAX_VEX];
    EdgeType edges[MAX_VEX][MAX_VEX];
    int vexnum, edgenum;
} MGraph;

// 队列结点
typedef struct QNode {
    int             data;
    struct QNode    *next;
} QNode, *QueuePtr;

// 链式队列结构
typedef struct {
    QueuePtr    front;
    QueuePtr    rear;
} LinkQueue;

// 初始化队列
void InitQueue(LinkQueue *Q)
{
    QNode *head = (QNode *)malloc(sizeof(QNode));

    Q->front = head;
    Q->rear = head;
    head->next = NULL;
}

// 判断队列是否为空
bool isEmptyQueue(LinkQueue Q)
{
    if (Q.front == Q.rear)
        return true;
    return false;
}

// 入队
void EnQueue(LinkQueue *Q, int e)
{
    QNode *new_node = (QNode *)malloc(sizeof(QNode));

    new_node->data = e;
    new_node->next = NULL;
    Q->rear->next = new_node;
    Q->rear = new_node;
}

// 出队
void DeQueue(LinkQueue *Q, int *e)
{
    if (Q->front == Q->rear) {
        fprintf(stderr, "队列为空，无法出队！\n");
        exit(EXIT_FAILURE);
    }
    *e = Q->front->next->data;

    QNode*temp = Q->front->next;        // 指向队首元素
    Q->front->next = temp->next;        // 队首更新
    
    if (Q->rear == temp)                // 如果只有一个元素 -- 则让头尾指针相等
        Q->front = Q->rear;
    free(temp);
}

// 定位某个值在图中的位置 -- 找到返回下标，找不到则返回-1
int LocateVex_MG(MGraph G, ElemType e)
{
    int i;
    for (i = 0; (i < G.vexnum) && (G.vex[i]!=e); i++)
        continue;
    if (i < G.vexnum)
        return i;
    else
        return -1;
}

// 创建无向图的邻接矩阵
void CreateUDG_MG(MGraph *G)
{
    // 读入图的顶点数和边数
    printf("请输入图的顶点数和边数：");
    scanf("%d %d", &G->vexnum, &G->edgenum);
    fflush(stdin);
    // 读入图的顶点信息
    for (int i = 0; i < G->vexnum; i++) {
        printf("请输入第%d个顶点信息：", i + 1);
        scanf("%c", &G->vex[i]);
        fflush(stdin);
    }
    // 初始化边为false
    for (int i = 0; i < G->vexnum; i++)
        for (int j = 0; j < G->vexnum; j++)
            G->edges[i][j] = false;
    // 创建边
    puts("现在请输入边信息, 输入边依附的两个顶点即可：");
    for (int k = 0; k < G->edgenum; k++) {
        ElemType vi, vj;
        
        printf("请输入第%d条边：", k + 1);
        scanf("%c %c", &vi, &vj);
        fflush(stdin);

        // 获取输入的顶点在图中的位置
        int i = LocateVex_MG(*G, vi);
        int j = LocateVex_MG(*G, vj);

        // 判断输入的顶点是否在图中
        while ((i<0)||(i>G->vexnum-1)||
               (j<0)||(j>G->vexnum-1))
        {
            printf("你输入的顶点不在图中，请重新输入：");
            scanf("%c %c", &vi, &vj);
            i = LocateVex_MG(*G, vi);
            j = LocateVex_MG(*G, vj);
            fflush(stdin);
        }
        // 无向图的邻接矩阵是对称矩阵
        G->edges[i][j] = G->edges[j][i] = true;
    }
}

// BFS遍历邻接矩阵
bool visited[MAX_VEX];
void BFSTraverse_MG(MGraph G)
{
    LinkQueue Q;
    InitQueue(&Q);

    // 初始化所有顶点为未访问状态
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = false;
    // k用于遍历每一个顶点, i和j用于指明边
    for (int k = 0; k < G.vexnum; k++) {
        int i, j;
        if (!visited[k]) {                  // 判断是否被访问过
            visited[k] = true;
            printf("%c", G.vex[k]);
            EnQueue(&Q, G.vex[k]);          // 必须先让第一个访问的顶点入队才能继续后面的循环
            while (!isEmptyQueue(Q)) {      // 寻找队首顶点的所有邻接顶点并输出入队
                DeQueue(&Q, &i);
                for (j = 0; j < G.vexnum; j++)
                    if (G.edges[i][j] && !visited[j]) {     // 存在边关系且未被访问过
                        visited[j] = true;
                        printf("%c", G.vex[j]);
                        EnQueue(&Q, j);
                    } // if
            } // while
        } // if
    } // for
}

// 测试
int main(void)
{
    MGraph G;

    CreateUDG_MG(&G);

    puts("BFS遍历结果如下：");
    BFSTraverse_MG(G);

    return 0;
}