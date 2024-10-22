// https://leetcode.cn/problems/reverse-nodes-in-k-group/description/?envType=study-plan-v2&envId=top-100-liked
 #include <utility>
 using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    pair<ListNode*, ListNode*> my_reverse(ListNode* head, ListNode* tail){
        ListNode* pre = tail->next;
        ListNode* cur = head;
        while(pre != tail){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return {tail, head};
    } 
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* tail = dummy;
        ListNode* cur = head;
        ListNode* pre = dummy;
        while(cur != nullptr){
            for(int i = 0; i < k; i++){
                tail = tail->next;
                if(tail == nullptr) return dummy->next;
            }      
            ListNode* next = tail->next;
            pair<ListNode*, ListNode*> result = my_reverse(cur, tail);
            cur = result.first;
            tail = result.second;
            pre->next = cur;
            tail->next = next;
            pre = tail;
            cur = tail->next;
        }
        return dummy->next;
    }
};