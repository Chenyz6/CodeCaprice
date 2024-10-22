// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/?envType=study-plan-v2&envId=top-100-liked

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        ListNode* tail = dummy;
        for(int i = 0; i < n + 1; i++){
            tail = tail->next;
        }

        while(tail != nullptr){
            tail = tail->next;
            cur = cur->next;
        }
        ListNode* del = cur->next;
        cur->next = cur->next->next;
        delete del; del = nullptr;
        
        ListNode* newHead = dummy->next;
        delete dummy;  // 删除虚拟头节点
        return newHead;
        // 不能返回head  在删除链表中的第一个节点时（当 n 等于链表的长度），head 会被删除
    }
};