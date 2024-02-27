// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = head;
        ListNode* end = head;
        for(int i = 0; i < n; i++){
            end = end->next; 
        }
        if(end == nullptr)  // 处理长度为n，删除倒数第n个的情况
        {
            ListNode* temp = head->next;
            delete head;
            return temp;
        }
        while (end->next != nullptr)
        {
            pre = pre->next;
            end = end->next;
        }
        ListNode* temp = pre->next;
        pre->next = pre->next->next;
        delete temp;
        return head;
    }
};

int main()
{
    return 0;
}