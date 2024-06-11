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
    TreeNode* Mirror(TreeNode* pRoot) {
        if(pRoot == nullptr) return nullptr;
        swap(pRoot->left, pRoot->right);
        if(pRoot->left) Mirror(pRoot->left);
        if(pRoot->right) Mirror(pRoot->right);
        return pRoot;
    }
};

int main()
{
    return 0;
}