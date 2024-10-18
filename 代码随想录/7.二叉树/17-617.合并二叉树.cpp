// https://leetcode.cn/problems/merge-two-binary-trees/

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr) return root2;
        if(root2 == nullptr) return root1;
        // 修改了t1的数值和结构
        root1->val += root2->val;                                // 中
        root1->left = mergeTrees(root1->left, root2->left);      // 左
        root1->right = mergeTrees(root1->right, root2->right);   // 右
        return root1;
    }
};