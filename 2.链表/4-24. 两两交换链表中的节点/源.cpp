// https://leetcode.cn/problems/swap-nodes-in-pairs/

#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* VirHead = new ListNode;
        VirHead->next = head;
        ListNode* cur = VirHead;
        while (cur->next != NULL && cur->next->next != NULL)
        {
            ListNode* temp = cur->next;
            ListNode* temp1 = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = temp;
            temp->next = temp1;
            cur = cur->next->next;
        }
        return VirHead->next;
    }
};

int main()
{
	system("pause");
}