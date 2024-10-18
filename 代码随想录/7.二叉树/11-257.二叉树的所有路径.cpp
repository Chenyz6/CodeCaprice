// https://leetcode.cn/problems/binary-tree-paths/
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
    vector<string> result;
    void getPaths(TreeNode* node, vector<int> & str){
        str.push_back(node->val);
        if(node->left == nullptr && node->right == nullptr){
            string s;
            for(int i = 0; i < str.size() - 1; i++){
                s += to_string(str[i]); 
                s += "->";   
            }
            s += to_string(str[str.size() - 1]);
            result.push_back(s);
            return;
        }
        if(node->left){
            getPaths(node->left, str);
            str.pop_back();
        }
        if(node->right){
            getPaths(node->right, str);
            str.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> str;
        getPaths(root, str);
        return result;
    }
};