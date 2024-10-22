// https://leetcode.cn/problems/add-two-numbers/?envType=study-plan-v2&envId=top-100-liked

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr, *cur = nullptr;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr){
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if(head == nullptr){
                head = cur = new ListNode(sum % 10);
            }else{
                cur->next = new ListNode(sum % 10);
                cur = cur->next;
            }
            carry = sum / 10;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        if(carry > 0){
            cur->next = new ListNode(carry);
        }
        return head;
    }
};