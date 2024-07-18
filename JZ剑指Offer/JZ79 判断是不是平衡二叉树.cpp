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
        // 它取左子树和右子树深度的最大值，并加上 1（表示当前节点），以得到当前树的深度。
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

// 自底向上
class Solution {
public:
    //计算该子树深度
    bool judge(TreeNode* root, int& depth){
        //空节点深度为0
        if(root == NULL){ 
            depth = 0;
            return true;
        }
        //准备计算左右子树的深度
        int left = 0; 
        int right = 0;
        if(judge(root->left, left) == false || judge(root->right, right) == false)
            return false;
        //左子树深度减去右子树相差绝对值大于1
        if(left - right > 1 || left - right < -1)
            return false;
        //子树最大深度加上自己
        depth = (left > right) ? left + 1 : right + 1; 
        //该节点满足要求
        return true; 
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return judge(pRoot, depth);
    }
};


int main()
{
    return 0;
}