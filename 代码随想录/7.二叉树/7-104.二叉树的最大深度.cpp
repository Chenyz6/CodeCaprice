// https://leetcode.cn/problems/maximum-depth-of-binary-tree/
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
/*
    递归法
    本题可以使用前序（中左右），也可以使用后序遍历（左右中），使用前序求的就是深度，使用后序求的是高度。
    二叉树节点的深度：指从根节点到该节点的最长简单路径边的条数或者节点数（取决于深度从0开始还是从1开始）
    二叉树节点的高度：指从该节点到叶子节点的最长简单路径边的条数或者节点数（取决于高度从0开始还是从1开始）
    而根节点的高度就是二叉树的最大深度，所以本题中我们通过后序求的根节点高度来求的二叉树最大深度。
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 后续遍历的方式
class Solution {
public:
    int getDepth(TreeNode* node){
        if(node == nullptr) return 0;
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);
        int maxDepth = max(leftDepth, rightDepth) + 1;
        return maxDepth;
    }
    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }
};

// 前续遍历的方式  回溯
class Solution {
public:
    int result;
    void getDepth(TreeNode* node, int Depth){
        result = Depth > result ? Depth : result;
        if(node->left == nullptr && node->right == nullptr) return;
        if(node->left){
            Depth++;
            getDepth(node->left, Depth);
            Depth--;
        }
        if(node->right){
            Depth++;
            getDepth(node->right, Depth);
            Depth--;
        }
        return ;
    }
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        getDepth(root, 1);
        return result;
    }
};


// 层序遍历的方式
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue <TreeNode*> que;
        int maxDepth = 0;
        if(root == nullptr) return 0;
        que.push(root); 
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* temp = que.front(); que.pop();
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            maxDepth++;
        }
        return maxDepth;
    }
};