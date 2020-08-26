// 递归实现
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL)
        return head;
    else {
        struct ListNode *new_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
}
