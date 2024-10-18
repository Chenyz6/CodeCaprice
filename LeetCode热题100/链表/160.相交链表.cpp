// https://leetcode.cn/problems/intersection-of-two-linked-lists/?envType=study-plan-v2&envId=top-100-liked
// (a + c  b ) + c  
// (b + c  a ) + c
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(curA != curB){
            if(curA == nullptr) {
                curA = headB;
            }else{
                curA = curA->next;
            }
            if(curB == nullptr) {
                curB = headA;
            }else{
                curB = curB->next;
            }
        }
        return curA;
    }
}; 