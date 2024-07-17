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

// 自上往下
class Solution {
  public:
    //计算该子树深度函数
    int deep(TreeNode* root) {
        //空节点深度为0
        if (root == NULL)
            return 0;
        //递归算左右子树的深度
        int left = deep(root->left);
        int right = deep(root->right);
        //子树最大深度加上自己
        return (left > right) ? left + 1 : right + 1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        //空树为平衡二叉树
        if (pRoot == NULL)
            return true;
        int left = deep(pRoot->left);
        int right = deep(pRoot->right);
        //左子树深度减去右子树相差绝对值大于1
        if (left - right > 1 || left - right < -1) {
            return false;
        }
        //同时，左右子树还必须是平衡的
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
};

int main()
{
    return 0;
}