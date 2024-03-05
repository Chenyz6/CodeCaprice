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

// 前序遍历
class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack <TreeNode *> st;
        vector <int> vec;
        if(root == nullptr) return {};
        st.push(root);
        while (!st.empty()){
            TreeNode* node = st.top();
            vec.push_back(node->val);
            st.pop();
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return vec;
    }
};

// 中序遍历
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack <TreeNode*> st;
        vector <int> result;
        TreeNode* cur = root;
        if(cur == nullptr) return {};
        while (cur != nullptr || !st.empty())
        {
            if(cur != nullptr){
                st.push(cur);
                cur = cur->left;
            }else{
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};

// 后序遍历
class Solution3 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack <TreeNode*> st;
        if(root == nullptr) return {};
        st.push(root);
        while (!st.empty()){
            TreeNode* cur = st.top();
            st.pop();
            result.push_back(cur->val);
            if(cur->left) st.push(cur->left);
            if(cur->right) st.push(cur->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{

    return 0;
}