// 栈实现
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    int size = 0;
    struct ListNode *p = head;

    // 计算head的结点个数
    while (p) {
        size++;
        p = p->next;
    }

    // 创建一个存储指向结点指针的栈
    struct ListNode *stack[size];
    int top = -1;

    // 让head的元素顺序入栈
    p = head;
    while (p) {
        stack[++top] = p;
        p = p->next;
    }

    // 将栈中元素弹出并储存在一个新的链表中
    struct ListNode *head_new = stack[top];

    p = head_new;
    while (top != -1) {
        p->next = stack[top--];
        p = p->next;
    }
    p->next = NULL;

    return head_new;
}
