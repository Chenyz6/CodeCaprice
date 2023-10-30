//https://leetcode.cn/problems/design-linked-list/

#include<iostream>
using namespace std;

//struct ListNode {
//	int val;
//	ListNode* next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode* next) : val(x), next(next) {}
//};

/*你可以选择使用单链表或者双链表，设计并实现自己的链表。

单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。

如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

实现 MyLinkedList 类：

MyLinkedList() 初始化 MyLinkedList 对象。
int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。*/

class MyLinkedList {
struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {};
	};
public:
    MyLinkedList() {
        head = new ListNode();
        num = 0;
    }

    int get(int index) {
        ListNode* res = head;
        if (index < 0) {
            return -1;
        }
        else if (index == 0) {
            return res->val;
        }
        for (int i = 0; i < index; i++) {
            res = res->next;
        }
        while (res != NULL && index > 0)
        {
            res = res->next;
            index--;
        }
        return res->val;
    }

    void addAtHead(int val) {
        ListNode* temp = new ListNode;
        temp->val = val;
        temp->next = head;
        head = temp;
    }

    void addAtTail(int val) {
        ListNode* temp = head;
        ListNode* pre = head;
        while (temp != NULL)
        {
            pre = temp;
            temp = temp->next;
        }
        ListNode* temp = new ListNode;
        temp->val = val;
        pre->next = temp;
        temp->next = NULL;
    }

    void addAtIndex(int index, int val) {
        ListNode* res = head;
		for (int i = 0; i < index; i++) {
			res = res->next;
		}
    }

    void deleteAtIndex(int index) {

    }
private:
    ListNode* head;
    int num;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
	system("pause");
}