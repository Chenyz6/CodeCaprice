// https://leetcode.cn/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-100-liked

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* preHead = new ListNode(-1);
        ListNode* pre = preHead;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                pre->next = list1;
                list1 = list1->next;
            }else{
               pre->next = list2;
               list2 = list2->next; 
            }
            pre = pre->next;
        }
        pre->next = list1 == nullptr ? list2 : list1;
        return preHead->next;
    }
};