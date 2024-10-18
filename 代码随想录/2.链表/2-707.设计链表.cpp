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
        for (int i = 0; i < index; i++) {
            res = res->next;
            if (res == NULL) {
                return -1;
            }
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
        ListNode* temp1 = new ListNode;
        temp1->val = val;
        pre->next = temp1;
        temp1->next = NULL;
    }

    void addAtIndex(int index, int val) {
        if (index < 0) {
			ListNode* temp = new ListNode;
			temp->val = val;
			temp->next = head;
			head = temp;
            return;
        }
        ListNode* res = head;
		for (int i = 0; i < index; i++) {
			res = res->next;
		}
        ListNode* temp = new ListNode;
        temp->val = val;
        temp->next = res->next;
        res->next = temp;
    }

    void deleteAtIndex(int index) {
        if (index < 0) return;
        if (index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
		ListNode* pre = head;
		while (index--)
		{
            pre = pre->next;
		}
        ListNode* tmp = pre->next;
		pre->next = pre->next->next;
		delete tmp;
		tmp = nullptr;
    }
private:
    ListNode* head;
    int num;
};

// 官方解
class MyLinkedList1 {
public:
	// 定义链表节点结构体
	struct LinkedNode {
		int val;
		LinkedNode* next;
		LinkedNode(int val) :val(val), next(nullptr) {}
	};

	// 初始化链表
	MyLinkedList1() {
		_dummyHead = new LinkedNode(0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
		_size = 0;
	}

	// 获取到第index个节点数值，如果index是非法数值直接返回-1， 注意index是从0开始的，第0个节点就是头结点
	int get(int index) {
		if (index > (_size - 1) || index < 0) {
			return -1;
		}
		LinkedNode* cur = _dummyHead->next;
		while (index--) { // 如果--index 就会陷入死循环
			cur = cur->next;
		}
		return cur->val;
	}

	// 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
	void addAtHead(int val) {
		LinkedNode* newNode = new LinkedNode(val);
		newNode->next = _dummyHead->next;
		_dummyHead->next = newNode;
		_size++;
	}

	// 在链表最后面添加一个节点  !!!!!!
	void addAtTail(int val) {
		LinkedNode* newNode = new LinkedNode(val);
		LinkedNode* cur = _dummyHead;
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		cur->next = newNode;
		_size++;
	}

	// 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
	// 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
	// 如果index大于链表的长度，则返回空
	// 如果index小于0，则在头部插入节点
	void addAtIndex(int index, int val) {

		if (index > _size) return;
		if (index < 0) index = 0;
		LinkedNode* newNode = new LinkedNode(val);
		LinkedNode* cur = _dummyHead;
		while (index--) {
			cur = cur->next;
		}
		newNode->next = cur->next;
		cur->next = newNode;
		_size++;
	}

	// 删除第index个节点，如果index 大于等于链表的长度，直接return，注意index是从0开始的
	void deleteAtIndex(int index) {
		if (index >= _size || index < 0) {
			return;
		}
		LinkedNode* cur = _dummyHead;
		while (index--) {
			cur = cur->next; 
		}
		LinkedNode* tmp = cur->next;
		cur->next = cur->next->next;
		delete tmp;
		//delete命令指示释放了tmp指针原本所指的那部分内存，
		//被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
		//如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
		//如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
		tmp = nullptr;
		_size--;
	}

	// 打印链表
	void printLinkedList() {
		LinkedNode* cur = _dummyHead;
		while (cur->next != nullptr) {
			cout << cur->next->val << " ";
			cur = cur->next;
		}
		cout << endl;
	}
private:
	int _size;
	LinkedNode* _dummyHead;
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