// 迭代实现
struct ListNode {
    int val;
    struct ListNode *next;
};

// 用头插法创建一个新的链表即可
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *res = NULL;
    struct ListNode *temp;

    while (head) {
        temp = head->next;
        head->next = res;
        res = head;
        head = temp;
    }
    return res;
}