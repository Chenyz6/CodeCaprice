//https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder){
        if(postorder.size() == 0) return nullptr;
        
        TreeNode* root = new TreeNode;
        root->val = postorder[postorder.size() - 1];

        int inIndex = INT16_MIN;
        for (inIndex = 0; inIndex < inorder.size(); inIndex++){
            if(postorder[postorder.size() - 1] == inorder[inIndex]) break;
        }

        // 左闭右开
        vector<int> leftInorder(inorder.begin(), inorder.begin() + inIndex);
        vector<int> rightInorder(inorder.begin() + inIndex + 1, inorder.end()); // 注意+1

        postorder.resize(postorder.size() - 1);
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + inIndex);
        vector<int> rightPostorder(postorder.begin() + inIndex, postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return traversal(inorder, postorder);
    }
};

int main()
{
    Solution s;
    vector<int> in {1};
    vector<int> post {1};
    s.buildTree(in, post);
}