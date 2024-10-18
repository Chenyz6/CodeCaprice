// https://leetcode.cn/problems/validate-binary-search-tree/
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

// 错误解法
class Solution {
    bool isValid = true;
public:
    void traversal(TreeNode* root, bool left, int lastVal){
        if(root == nullptr) return;
        if(left){
            if(lastVal <= root->val) isValid = false;
            if(root->left) if(root->left->val >= lastVal) isValid = false;
            if(root->right) if(root->right->val >= lastVal) isValid = false;
                
        }else{
            if(lastVal >= root->val) isValid = false;
            if(root->left) if(root->left->val <= lastVal) isValid = false;
            if(root->right) if(root->right->val <= lastVal) isValid = false;
        }
        if(root->left){
            if(root->val <= root->left->val) isValid = false;
        }
        if(root->right){
            if(root->val >= root->right->val) isValid = false;
        }
        if(root->left) {
            traversal(root->left, true, root->val);
        }
        if(root->right) {
            traversal(root->right, false, root->val);
        }
    }
    bool isValid1(TreeNode* root) {
        traversal(root, false, INT32_MIN);
        return isValid;
    }
};

class Solution {
    vector<int> vec;
public:
    void traversal(TreeNode* root){
        if(root == nullptr) return;
        if(root->left) traversal(root->left);
        vec.push_back(root->val);
        if(root->right) traversal(root->right);
    }
    bool isValid(TreeNode* root) {
        traversal(root);
        if (vec.size() == 1) return true;
        for(int i = 0; i < vec.size() - 1; i++){
            if(vec[i] >= vec[i + 1]) return false;
        }
        return true;
    }
};