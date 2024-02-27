// https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/description/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;int lenB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(curA != nullptr){
            lenA++;
            curA = curA->next;
        }
        while(curB != nullptr){
            lenB++;
            curB = curB->next;
        }
        // 优化
        // // 让curA为最长链表的头，lenA为其长度
        // if (lenB > lenA) {
        //     swap (lenA, lenB);
        //     swap (curA, curB);
        // }
        // // 求长度差
        // int gap = lenA - lenB;
        // // 让curA和curB在同一起点上（末尾位置对齐）
        // while (gap--) {
        //     curA = curA->next;
        // }
        if(lenA > lenB){
            curA = headA;
            curB = headB;
            for(int i = 0; i < lenA - lenB; i++){
                curA = curA->next;
            }
            while (curA != nullptr)
            {
                if(curA == curB) return curA;
                curA = curA->next;
                curB = curB->next;
            }
        }else{
            curA = headA;
            curB = headB;
            for(int i = 0; i < lenB - lenA; i++){
                curB = curB->next;
            }
            while (curA != nullptr)
            {
                if(curA == curB) return curA;
                curA = curA->next;
                curB = curB->next;
            }
        }
        return nullptr;
    }
};

int main()
{
    return 0;
}
