#include <iostream>
#include <vector>
#include <stack>
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

// 中序遍历
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack <TreeNode *> st;
        vector <int> result;
        if(root == nullptr) return {};
        st.push(root);
        while (!st.empty()){
            TreeNode * cur = st.top();
            if(cur != nullptr){
                st.pop();
                if(cur->right) st.push(cur->right);
                st.push(cur);
                st.push(nullptr);
                if(cur->left) st.push(cur->left);
            }else{
                st.pop();
                result.push_back(st.top()->val);
                st.pop();
            }
        }
        return result;
    }
};
