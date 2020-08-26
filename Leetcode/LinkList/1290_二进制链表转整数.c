// 栈解法
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int getDecimalValue(struct ListNode* head){
    struct ListNode * stack[30];        // 创建一个栈
    struct ListNode * p = head;         // 指向链表的第一个结点
    int top = -1;                       // 栈顶指针
    int res = 0;                        // 返回的结果
    int exp = 1;                        // 每一位乘相应次数2后的结果
    int size;                           // 栈中的元素个数(从0开始数)

    // 链表二进制数入栈
    while (p) {
        stack[++top] = p;
        p = p->next;
    }
    // 获取栈中元素个数(从0开始数)
    size = top;
    
    // 最低位如果是1则让res=1 -- 因为最低位要么是1要么是0
    // 而循环中每次操作是乘以2
    if (stack[top--]->val) res=1;

    while (top != -1) {             // 让栈顶元素出栈并乘以相应次数的2
        for (int i = 0; i<size-top;i++)
            exp *= stack[top]->val * 2;
        res += exp;
        exp = 1;
        top--;
    }
    return res;
}

int main(void)
{
    struct ListNode *head = NULL;
    struct ListNode *p;

    int data[4] = {1, 1, 0, 1};

    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = head;
    for (int i = 0; i < 4; i++) {
        struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        
        new_node->val = data[i];
        new_node->next = NULL;
        p->next = new_node;
        p = new_node;
    }
    
    printf("%d", getDecimalValue(head->next));

    return 0;
}