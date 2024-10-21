// https://leetcode.cn/problems/linked-list-cycle/?envType=study-plan-v2&envId=top-100-liked
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 哈希表的方式
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> un_set;
        ListNode* cur = head;
        while(cur != nullptr){
            if(un_set.find(cur) != un_set.end()) return true;
            un_set.insert(cur);
            cur = cur->next;
        }
        return false;
    }
};

// 快慢指针
class Solution1 {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};