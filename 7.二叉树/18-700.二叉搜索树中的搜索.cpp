// https://leetcode.cn/problems/search-in-a-binary-search-tree/description/

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
    TreeNode* result = nullptr;
    void traversal(TreeNode* root, int val){
        if(root == nullptr) return;
        if(root->val == val) result = root;
        if(root->left && val < root->val){
            traversal(root->left, val);
        }
        if(root->right && val > root->val){
            traversal(root->right, val);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        traversal(root, val);
        return result;
    }
};

