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
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (pHead == nullptr) return nullptr;
        ListNode* slow = pHead;
        ListNode* fast = pHead;
        if (pHead->next == nullptr || pHead->next->next == nullptr) return nullptr;
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                int num = 1;
                ListNode* temp = slow->next;
                while (slow != temp) {
                    num++;
                    temp = temp->next;
                }
                fast = slow = pHead;
                for (int i = 0; i < num; i++) {
                    fast = fast->next;
                }
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};

int main()
{
    return 0;
}