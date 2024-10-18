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

/*�����ѡ��ʹ�õ��������˫������Ʋ�ʵ���Լ�������

�������еĽڵ�Ӧ�þ߱��������ԣ�val �� next ��val �ǵ�ǰ�ڵ��ֵ��next ��ָ����һ���ڵ��ָ��/���á�

�����˫����������Ҫ���� prev ��ָʾ�����е���һ���ڵ㡣���������е����нڵ��±�� 0 ��ʼ��

ʵ�� MyLinkedList �ࣺ

MyLinkedList() ��ʼ�� MyLinkedList ����
int get(int index) ��ȡ�������±�Ϊ index �Ľڵ��ֵ������±���Ч���򷵻� -1 ��
void addAtHead(int val) ��һ��ֵΪ val �Ľڵ���뵽�����е�һ��Ԫ��֮ǰ���ڲ�����ɺ��½ڵ���Ϊ����ĵ�һ���ڵ㡣
void addAtTail(int val) ��һ��ֵΪ val �Ľڵ�׷�ӵ���������Ϊ��������һ��Ԫ�ء�
void addAtIndex(int index, int val) ��һ��ֵΪ val �Ľڵ���뵽�������±�Ϊ index �Ľڵ�֮ǰ����� index ��������ĳ��ȣ���ô�ýڵ�ᱻ׷�ӵ������ĩβ����� index �ȳ��ȸ��󣬸ýڵ㽫 ������� �������С�
void deleteAtIndex(int index) ����±���Ч����ɾ���������±�Ϊ index �Ľڵ㡣*/

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

// �ٷ���
class MyLinkedList1 {
public:
	// ��������ڵ�ṹ��
	struct LinkedNode {
		int val;
		LinkedNode* next;
		LinkedNode(int val) :val(val), next(nullptr) {}
	};

	// ��ʼ������
	MyLinkedList1() {
		_dummyHead = new LinkedNode(0); // ���ﶨ���ͷ��� ��һ������ͷ��㣬����������������ͷ���
		_size = 0;
	}

	// ��ȡ����index���ڵ���ֵ�����index�ǷǷ���ֱֵ�ӷ���-1�� ע��index�Ǵ�0��ʼ�ģ���0���ڵ����ͷ���
	int get(int index) {
		if (index > (_size - 1) || index < 0) {
			return -1;
		}
		LinkedNode* cur = _dummyHead->next;
		while (index--) { // ���--index �ͻ�������ѭ��
			cur = cur->next;
		}
		return cur->val;
	}

	// ��������ǰ�����һ���ڵ㣬������ɺ��²���Ľڵ�Ϊ������µ�ͷ���
	void addAtHead(int val) {
		LinkedNode* newNode = new LinkedNode(val);
		newNode->next = _dummyHead->next;
		_dummyHead->next = newNode;
		_size++;
	}

	// ��������������һ���ڵ�  !!!!!!
	void addAtTail(int val) {
		LinkedNode* newNode = new LinkedNode(val);
		LinkedNode* cur = _dummyHead;
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		cur->next = newNode;
		_size++;
	}

	// �ڵ�index���ڵ�֮ǰ����һ���½ڵ㣬����indexΪ0����ô�²���Ľڵ�Ϊ�������ͷ�ڵ㡣
	// ���index ��������ĳ��ȣ���˵�����²���Ľڵ�Ϊ�����β���
	// ���index��������ĳ��ȣ��򷵻ؿ�
	// ���indexС��0������ͷ������ڵ�
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

	// ɾ����index���ڵ㣬���index ���ڵ�������ĳ��ȣ�ֱ��return��ע��index�Ǵ�0��ʼ��
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
		//delete����ָʾ�ͷ���tmpָ��ԭ����ָ���ǲ����ڴ棬
		//��delete���ָ��tmp��ֵ����ַ�����Ǿ���NULL���������ֵ��Ҳ���Ǳ�delete��
		//������ټ���һ��tmp=nullptr,tmp���Ϊ��ָ��Ұָ��
		//���֮��ĳ���С��ʹ����tmp����ָ������Ԥ����ڴ�ռ�
		tmp = nullptr;
		_size--;
	}

	// ��ӡ����
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