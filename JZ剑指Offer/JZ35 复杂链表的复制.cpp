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


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    void CloneNodes(RandomListNode* pHead){
        RandomListNode* cur = pHead;
        while(cur != nullptr){
            RandomListNode* temp = new RandomListNode(cur->label);
            RandomListNode* next = cur->next;
            temp->next = next;
            cur->next = temp;
            cur = next;
        }
    }
    void ConnectSiblingNodes(RandomListNode* pHead){
        RandomListNode* cur = pHead;
        while(cur != nullptr){
            RandomListNode* next = cur->next;
            if(cur->random != nullptr){   // 注意 cur->random != nullptr
                next->random = cur->random->next;    
            }
            cur = next->next;
        }
    }
    RandomListNode* ReconnectNodes(RandomListNode* pHead){
        RandomListNode* head = pHead->next;
        RandomListNode* cur = head;
        if(pHead != nullptr) {delete pHead; pHead = nullptr;}
        while(cur != nullptr && cur->next != nullptr){  // 注意 cur->next != nullptr
            RandomListNode* del = cur->next;  
            cur->next = cur->next->next;
            cur = del->next;
            if(del != nullptr) {delete del; del = nullptr;}
        }
        return head;
    }
    RandomListNode* Clone(RandomListNode* pHead) {
        if(pHead == nullptr) return nullptr;
        CloneNodes(pHead);
        ConnectSiblingNodes(pHead);
        return ReconnectNodes(pHead);
    }
};





int main()
{
    return 0;
}