// 合并两个升序链表 -- 迭代实现
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    ListNode *ph = head;

    // 遍历l1,l2 -- 较小的就让ph->next指向它
    while (l1 && l2) {
        if (l1->val < l2->val) {
            ph->next = l1;
            l1 = l1->next;
        }
        else {
            ph->next = l2;
            l2 = l2->next;
        }
        ph = ph->next;
    }
    if (l1)
        ph->next = l1;
    if (l2)
        ph->next = l2;

    return head->next;
}