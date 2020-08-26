// 快慢指针实现

bool hasCycle(struct ListNode *head) {
    // 空链表没有环
    if (head == NULL || head->next == NULL) return false;

    struct ListNode * slow, * fast;     // 定义快慢指针
    slow = head;
    fast = head->next;

    while (fast != NULL && fast->next !=NULL) {
        if (fast == slow) return true;      // 快慢指针相遇说明有环
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}