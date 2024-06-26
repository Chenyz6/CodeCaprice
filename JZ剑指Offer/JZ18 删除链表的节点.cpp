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
    ListNode* deleteNode(ListNode* head, int val) {
        while(head->val == val){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            temp = nullptr;
        }
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            if(cur->val == val){
                pre->next = cur->next;
                delete cur;
                cur = nullptr;
            }else{
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

int main()
{
    return 0;
}