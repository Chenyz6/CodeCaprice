// https://leetcode.cn/problems/count-complete-tree-nodes/
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

// 层序遍历
class Solution {
public:
    int countNodes(TreeNode* root) {
        int result = 0;
        if(root == nullptr) return result;
        queue <TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            result += size;
            for(int i = 0; i < size; i++){
                TreeNode* temp = que.front();
                que.pop();
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
        }
        return result;
    }
};

// 二叉树性质
class Solution1 {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;
        int leftLen = 0,rightLen = 0;
        while (leftNode != nullptr){
            leftNode = leftNode->left;
            leftLen++;
        }
        while (rightNode != nullptr){
            rightNode = rightNode->right;
            rightLen++;
        }
        if(rightLen == leftLen) return (2 << rightLen) - 1;  // 此行可以注释
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};