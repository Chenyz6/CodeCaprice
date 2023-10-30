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