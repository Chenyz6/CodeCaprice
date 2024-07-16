#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

// 
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == nullptr || pHead2 == nullptr) return nullptr;
		int head1Len = 0, head2Len = 0;
		ListNode* cur = pHead1;
		while(cur != nullptr){
			head1Len++;
			cur = cur->next;
		}
		cur = pHead2;
		while(cur != nullptr){
			head2Len++;
			cur = cur->next;
		}
		ListNode* cur1 = pHead1;
		if(head1Len > head2Len){
			cur = pHead1;
			for(int i = 0; i < head1Len - head2Len; i++){
				cur = cur->next;
			}
			cur1 = pHead2;
			while(cur != cur1){
				cur = cur->next;
				cur1 = cur1->next;
			}
			return cur;
		}else{
			cur = pHead2;
			for(int i = 0; i < head2Len - head1Len; i++){
				cur = cur->next;
			}
			cur1 = pHead1;
			while(cur != cur1){
				cur = cur->next;
				cur1 = cur1->next;
			}
			return cur;
		}
    }
};


int main()
{
    return 0;
}