// https://leetcode.cn/problems/sum-of-left-leaves/description/
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
    int sum = 0;
    void sumLeft(TreeNode* node, bool left){
        if(node == nullptr){
            return;
        }
        if(left && node->left == nullptr && node->right == nullptr){
            sum += node->val;
        }
        if(node->left) sumLeft(node->left, true);
        if(node->right) sumLeft(node->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        sumLeft(root, false);
        return sum;
    }
};