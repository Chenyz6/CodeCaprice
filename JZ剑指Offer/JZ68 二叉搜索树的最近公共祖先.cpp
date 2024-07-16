#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
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
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        //空树找不到公共祖先
        if(root == NULL) 
            return -1;
        //pq在该节点两边说明这就是最近公共祖先
        if((p >= root->val && q <= root->val) || (p <= root->val && q >= root->val)) 
            return root->val;
        //pq都在该节点的左边
        else if(p <= root->val && q <= root->val) 
            //进入左子树
            return lowestCommonAncestor(root->left, p, q); 
        //pq都在该节点的右边
        else 
            //进入右子树
            return lowestCommonAncestor(root->right, p, q); 
    }
};

int main()
{
    return 0;
}