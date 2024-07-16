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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		if(root == nullptr) return {};
		queue<TreeNode* > que; vector<int> result;
		que.push(root);
		while(!que.empty()){
			TreeNode* temp = que.front();
			result.push_back(temp->val);
			que.pop();
			if(temp->left) que.push(temp->left);
			if(temp->right) que.push(temp->right);
		}
		return result;
    }
};

int main()
{
    return 0;
}