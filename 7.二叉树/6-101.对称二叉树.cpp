// https://leetcode.cn/problems/symmetric-tree/description/
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

// 递归
class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right){
        if(left == nullptr && right != nullptr) return false;
        else if(left != nullptr && right == nullptr) return false;
        else if(left == nullptr && right == nullptr) return true;
        else if(left->val != right->val) return false;

        bool outside = compare(left->left, right->right);  // 比较的是整颗树
        bool inside = compare(left->right, right->left);
        return outside && inside;
    }
    bool isSymmetric(TreeNode* root) {
        return compare(root->left, root->right);
    }
};

// 遍历
class Solution1 {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        queue <TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while (!que.empty())
        {
            TreeNode* left = que.front(); que.pop();
            TreeNode* right = que.front(); que.pop();
            if(left == nullptr && right == nullptr) continue;
            if(left != nullptr && right == nullptr) return false;
            if(left == nullptr && right != nullptr) return false;
            if(left->val != right->val) return false;
            que.push(left->left);
            que.push(right->right);
            que.push(left->right);
            que.push(right->left);
        }
        return true;
    }
};