// https://leetcode.cn/problems/palindrome-linked-list/?envType=study-plan-v2&envId=top-100-liked

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return false;
        int num = 0;
        ListNode* cur = head;
        while(cur != nullptr){
            num++;
            cur = cur->next;
        }
        cur = head; ListNode* pre = nullptr;
        for(int i = 0; i < num / 2; i++){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        if(num % 2 == 1) cur = cur->next;
        while(cur != nullptr){
            if(cur->val == pre->val){
                cur = cur->next; pre = pre->next;
            }else{
                return false;
            }
        }
        return true;
    }
};