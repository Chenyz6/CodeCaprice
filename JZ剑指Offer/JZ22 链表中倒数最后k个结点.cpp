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
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if(pHead == nullptr) return nullptr;
        if(k == 0) return nullptr;
        ListNode* begin = pHead;
        ListNode* end = begin;
        for(int i = 0; i < k - 1; i++){
            end = end->next;
        }
        if(end == nullptr) return nullptr;
        while (end->next != nullptr) {
            begin = begin->next;
            end = end->next;
        }
        return begin;
    }
};

int main()
{
    return 0;
}