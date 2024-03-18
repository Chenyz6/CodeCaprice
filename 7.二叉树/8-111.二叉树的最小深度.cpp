// https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
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

// 后序遍历
class Solution {
public:
    int getDepth(TreeNode* node){
        if(node == nullptr) return 0;
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);
        if(node->left == nullptr && node->right != nullptr){
            return ++rightDepth;
        }
        if(node->left != nullptr && node->right == nullptr){
            return ++leftDepth;
        }
        int result = 1 + min(leftDepth, rightDepth);
        return result;
    }
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return getDepth(root);
    }   
};