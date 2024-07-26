#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    int result = 0;
    void dfs(TreeNode* node, int sum){
        if(node == nullptr) return;
        if(sum == node->val) result++;
        dfs(node->left, sum - node->val);
        dfs(node->right, sum - node->val); 
    }
    int FindPath(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
        dfs(root, sum);
        FindPath(root->left, sum);
        FindPath(root->right, sum);
        return result; 
    }
};

int main()
{
    return 0;
}