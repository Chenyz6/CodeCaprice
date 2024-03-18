// https://leetcode.cn/problems/balanced-binary-tree/description/
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

// 递归方式
class Solution {
public:
    int getDepth(TreeNode* node) {
        if(node == nullptr) return 0;
        int leftDepth = getDepth(node->left);
        if(leftDepth == -1) return -1;
        int rightDepth = getDepth(node->right);
        if(rightDepth == -1) return -1;
        int num = abs(leftDepth - rightDepth); // abs求绝对值
        if(num > 1) return -1;
        return max(leftDepth, rightDepth) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(-1 == getDepth(root)) return false;
        return true;
    }
};