// https://leetcode.cn/problems/remove-linked-list-elements/
/*题意：删除链表中等于给定值 val 的所有节点。

示例 1： 输入：head = [1,2,6,3,4,5,6], val = 6 输出：[1,2,3,4,5]

示例 2： 输入：head = [], val = 1 输出：[]

示例 3： 输入：head = [7,7,7,7], val = 7 输出：[]*/

#include<iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
	 ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val)
        {
            ListNode* del = head;
            head = head->next;
            delete del;
		}
        ListNode* cur = head;
        while (cur != NULL && cur->next != NULL)
        {
            if (cur->next->val == val) {
                ListNode* del = cur->next;
                cur->next = cur->next->next;
                delete del;
            }
            else {
                cur = cur->next;
            }
        }
        return head;
	}
};

class Solution1 {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* cur = new ListNode;
        cur->next = head;
        ListNode* pre = cur;
		while (pre != NULL && pre->next != NULL)
		{
			if (pre->next->val == val) {
				ListNode* del = pre->next;
                pre->next = pre->next->next;
				delete del;
			}
			else {
                pre = pre->next;
			}
		}
        ListNode* result = cur->next;
        delete cur;
		return result;
	}
};

int main()
{
	system("pause");
}