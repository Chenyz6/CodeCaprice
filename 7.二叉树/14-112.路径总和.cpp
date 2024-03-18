// https://leetcode.cn/problems/path-sum/description/
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
    bool result = false;
    void traversal(TreeNode* node, int targetSum, int curSum){
        if(node->left == nullptr && node->right == nullptr){
            if(curSum == targetSum) result = true; 
            return;
        }
        if(node->left){
            curSum += node->left->val;
            traversal(node->left, targetSum, curSum);
            curSum -= node->left->val;
        }
        if(node->right){
            curSum += node->right->val;
            traversal(node->right, targetSum, curSum);
            curSum -= node->right->val;
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        traversal(root, targetSum, root->val);
        return result;
    }
};

// 优化递归直接返回结果
class Solution {
public:
    bool traversal(TreeNode* node, int targetSum, int curSum){
        if(node->left == nullptr && node->right == nullptr){
            if(curSum == targetSum) return true;
            return false;
        }
        if(node->left){
            curSum += node->left->val;
            if(traversal(node->left, targetSum, curSum)) return true;
            curSum -= node->left->val;
        }
        if(node->right){
            curSum += node->right->val;
            if(traversal(node->right, targetSum, curSum)) return true;
            curSum -= node->right->val;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        return traversal(root, targetSum, root->val);
    }
};

// 迭代方式
class Solution {
public:
    stack<pair<TreeNode*, int>> st;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        st.push(make_pair(root, root->val));
        while(!st.empty()){
            pair<TreeNode*, int> pa = st.top();
            st.pop();
            if(pa.first->left == nullptr && pa.first->right == nullptr){
                if(pa.second == targetSum){
                    return true;
                }
            }
            if(pa.first->right){
                st.push(make_pair(pa.first->right, pa.second + pa.first->right->val));
            }
            if(pa.first->left){
                st.push(make_pair(pa.first->left, pa.second + pa.first->left->val));
            }
        }
        return false;
    }
};