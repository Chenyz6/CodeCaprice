// https://leetcode.cn/problems/swap-nodes-in-pairs/description/?envType=study-plan-v2&envId=top-100-liked

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        while(pre->next != nullptr && pre->next->next != nullptr){
            ListNode* first = pre->next;
            ListNode* second = pre->next->next;
            first->next = second->next;
            second->next = first;
            pre->next = second;
            pre = first;
        }
        return dummy->next;
    }
};