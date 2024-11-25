// https://leetcode.cn/problems/merge-k-sorted-lists/?envType=study-plan-v2&envId=top-100-liked
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        if(lists.size() == 1) return lists[0];
        ListNode* newHead = new ListNode;
        ListNode* temp = new ListNode;
        ListNode* cur1, *cur2, *cur;
        for(int i = 1; i < lists.size(); i++){
            if(i == 1){
                cur1 = lists[0], cur2 = lists[i], cur = newHead;
            }else{
                cur1 = temp, cur2 = lists[i], cur = newHead;
            }
            while(cur1 != nullptr && cur2 != nullptr){
                if(cur1->val <= cur2->val){
                    cur->next = cur1;
                    cur1 = cur1->next;
                }else{
                    cur->next = cur2;
                    cur2 = cur2->next;
                }
                cur = cur->next;
            }
            if(cur1 != nullptr) cur->next = cur1;
            if(cur2 != nullptr) cur->next = cur2;
            temp = newHead->next; newHead = new ListNode;
        }
        return temp;
    }
};