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


/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if(pHead == nullptr) return nullptr;
        ListNode* res = new ListNode(0);
        res->next = pHead;
        ListNode* cur = res;
        while(cur->next != nullptr && cur->next->next != nullptr){
            if(cur->next->val == cur->next->next->val){
                int temp = cur->next->val;
                while(cur->next != nullptr && cur->next->val == temp){
                    cur->next = cur->next->next;
                }
            }else {
                cur = cur->next;
            }
        }
        return res->next;
    }
};

int main()
{
    return 0;
}