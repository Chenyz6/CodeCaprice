// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/

#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* last = head;
		ListNode* cur = head;
		while (n-- && last != NULL)
		{
			last = last->next;
		}
		while (last != NULL && last->next != NULL)
		{
			cur = cur->next;
			last = last->next;
		}
		ListNode* delNode = cur->next;
		if (cur->next != NULL)
		{
			cur->next = cur->next->next;
		}

		delete delNode;
		return head;
	}
};

int main()
{
	ListNode* Head = new ListNode;
	Head->val = 5;
	ListNode* cur = Head;
	//for (int i = 0; i < 3; i++)
	//{
	//	ListNode* temp = new ListNode;
	//	temp->val = i;
	//	cur->next = temp;
	//	cur = temp;
	//}
	cur->next = NULL;

	// 打印链表
	ListNode* cur1 = Head;
	while (cur1 != nullptr) {
		cout << cur1->val << " ";
		cur1 = cur1->next;
	}
	cout << endl;

	Solution s;
	s.removeNthFromEnd(Head,2);

	cout << "删除后" << endl;
	// 打印链表
	ListNode* cur2 = Head;
	while (cur2 != nullptr) {
		cout << cur2->val << " ";
		cur2 = cur2->next;
	}
	cout << endl;

	system("pause");
}