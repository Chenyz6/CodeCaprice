// https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/

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
    vector<int> vec;
    void traversal(TreeNode* root){
        if(root == nullptr) return;
        if(root->left) traversal(root->left);
        vec.push_back(root->val);
        if(root->right) traversal(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        int min = INT32_MAX;
        for(int i = 0; i < vec.size() - 1; i++){
            if(abs(vec[i] - vec[i + 1]) < min)
                min = abs(vec[i] - vec[i + 1]);
        }
        return min;
    }
};

// 迭代
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* last = nullptr;
        int result = INT32_MAX;   
        while (root != nullptr || !st.empty())
        {
            if(root != nullptr){
                st.push(cur);
                cur = cur->left;
            }else{
                cur = st.top();
                st.pop();
                if(last){
                    result = min(result, cur->val - last->val);
                }
                last = cur;
                cur = cur->right;
            }
        }
        return result;
    }
};