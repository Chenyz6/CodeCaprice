// https://leetcode.cn/problems/linked-list-cycle-ii/description/
#include <iostream>
using namespace std;

// 判断链表是否有环?
// 可以使用快慢指针法，分别定义 fast 和 slow 指针，
// 从头结点出发，fast指针每次移动两个节点，slow指针每次移动一个节点，
// 如果 fast 和 slow指针在途中相遇 ，说明这个链表有环。

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                slow = head;
                while (slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
int main()
{
    return 0;
}