// https://leetcode.cn/problems/remove-linked-list-elements/
/*���⣺ɾ�������е��ڸ���ֵ val �����нڵ㡣

ʾ�� 1�� ���룺head = [1,2,6,3,4,5,6], val = 6 �����[1,2,3,4,5]

ʾ�� 2�� ���룺head = [], val = 1 �����[]

ʾ�� 3�� ���룺head = [7,7,7,7], val = 7 �����[]*/

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