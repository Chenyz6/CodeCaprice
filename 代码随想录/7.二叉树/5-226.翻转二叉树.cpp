// https://leetcode.cn/problems/invert-binary-tree/description/
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
    void my_invert(TreeNode* node){
        if(node == nullptr) return;
        swap(node->right->val, node->left->val);
        if(node->right != nullptr) { 
            my_invert(node->right);
        }
        if(node->left != nullptr) {
            my_invert(node->left);
        }
    }

    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        my_invert(root);
        return root;
    }
};

// 迭代方式
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        stack <TreeNode* > st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode* temp = st.top();
            st.pop();
            swap(temp->left, temp->right);
            if(temp->left) st.push(temp->left);
            if(temp->right) st.push(temp->right);
        }
        return root;
    }
};

// 统一迭代方式
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        stack <TreeNode* > st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode* node = st.top();    
            if(node != nullptr){
                st.pop();
                if(node->right) st.push(node->right);
                if(node->left) st.push(node->left);                 
                st.push(node);
                st.push(nullptr);
            }else{
                st.pop();
                TreeNode* top = st.top();
                swap(top->right, top->left);
                st.pop();
            }
        }
        return root;
    }
};