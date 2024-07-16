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
    //返回的第一个指针，即为最小值，先定为NULL
    TreeNode* head = NULL;
    //中序遍历当前值的上一位，初值为最小值，先定为NULL
    TreeNode* pre = NULL;
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == NULL)
            //中序递归，叶子为空则返回
            return NULL;
        //首先递归到最左最小值
        Convert(pRootOfTree->left);
        //找到最小值，初始化head与pre
        if (pre == NULL) {
            head = pRootOfTree;
            pre = pRootOfTree;
        }
        //当前节点与上一节点建立连接，将pre设置为当前值
        else {
            pre->right = pRootOfTree;
            pRootOfTree->left = pre;
            pre = pRootOfTree;
        }
        Convert(pRootOfTree->right);
        return head;
    }
};

int main()
{
    return 0;
}