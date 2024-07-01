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

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    int index = 0;
    int result = -1;
    void mid(TreeNode* proot, int k){
        if(proot == nullptr) return;
        if(proot->left) mid(proot->left, k);
        index++;
        if(index == k) {
            result = proot->val;
            return;
        }
        if(proot->right) mid(proot->right, k);
    }
    int KthNode(TreeNode* proot, int k) {
        if(proot == nullptr) return -1;
        mid(proot, k);
        return result;
    }
};

int main()
{
    return 0;
}