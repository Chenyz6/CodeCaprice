// https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue <TreeNode*> que;
        if(root == nullptr) return {};
        vector<vector<int>> result;
        que.push(root);
        while (!que.empty()){
            // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
            int size = que.size();
            vector<int> vec;
            for(int i = 0; i < size; i++){
                TreeNode* cur = que.front();
                que.pop();
                vec.push_back(cur->val);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};