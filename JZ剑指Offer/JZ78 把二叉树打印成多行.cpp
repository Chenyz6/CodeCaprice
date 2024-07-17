#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <unordered_map>
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

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
#include <queue>
#include <vector>
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if(pRoot == nullptr) return {};
        vector<vector<int>> result;
        vector<int> path;
        queue<TreeNode*> que;
        que.push(pRoot);
        while(!que.empty()){
            int num = que.size();
            for(int i = 0; i < num; i++){  // 每一行的大小就是每层的数目
                TreeNode* cur = que.front();
                que.pop();
                path.push_back(cur->val);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);                
            }
            result.push_back(path); path.clear();
        }
        return result;
    }
};

int main()
{
    return 0;
}