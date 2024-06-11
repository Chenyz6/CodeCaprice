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

class Solution {
public:
	bool isEqual(TreeNode* pRoot1, TreeNode* pRoot2){
		if(pRoot2 == nullptr) return true;
		if(pRoot1 == nullptr) return false;
		bool left = false , right = false;
		if(pRoot1->val != pRoot2->val) return false;
		left = isEqual(pRoot1->left, pRoot2->left);
		right = isEqual(pRoot1->right, pRoot2->right);
		return left && right;
	}
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		if(pRoot2 == nullptr) return false;
		if(pRoot1 == nullptr) return false;
		queue<TreeNode*> que;
		que.push(pRoot1);
		while(!que.empty()){
			TreeNode* temp = que.front();
			que.pop();
			if(temp->val == pRoot2->val) {
				if(isEqual(temp, pRoot2)) return true;
			}
			if(temp->left) que.push(temp->left);
			if(temp->right) que.push(temp->right);
		}
		return false;
    }
};

int main()
{
    return 0;
}