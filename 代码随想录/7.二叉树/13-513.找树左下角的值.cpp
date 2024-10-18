// https://leetcode.cn/problems/find-bottom-left-tree-value/
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

// 层序遍历方式
class Solution {
public:
    queue <TreeNode*> que;
    int result;
    int findBottomLeftValue(TreeNode* root) {
        que.push(root);
        while (!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){
               TreeNode* node = que.front();  
               que.pop();
               if(i == 0) result = node->val;
               if(node->left) que.push(node->left);
               if(node->right) que.push(node->right);
            }
        }
        return result;
    }
};

// 递归方式
class Solution {
public:
    int maxDepth = INT16_MIN;
    int result = INT16_MIN;

    void my_find(TreeNode* node, int depth){
        if(node->left == nullptr && node->right == nullptr){
            if(depth > maxDepth){
                maxDepth = depth;
                result = node->val;   
            }
            return;
        }            
        if(node->left){
            depth++;
            my_find(node->left, depth);
            depth--;
        }
        if(node->right){
            depth++;
            my_find(node->right, depth);
            depth--;
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        if(root == nullptr) return -1;
        my_find(root, 1);
        return result;
    }
};