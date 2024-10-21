// https://leetcode.cn/problems/linked-list-cycle-ii/description/?envType=study-plan-v2&envId=top-100-liked
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 哈希表方法
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        ListNode* cur = head;
        unordered_set<ListNode*> un_set;
        while(cur != nullptr){
            if(un_set.find(cur) != un_set.end()){
                return cur;
            }else{
                un_set.insert(cur);
                cur = cur->next;
            }
        }
        return nullptr;
    }
};

// 快慢指针 数学法
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        bool hasCycle = false;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                hasCycle = true;
                break;
            }
        }
        if(hasCycle == false) return nullptr;
        ListNode* cur = head;
        while(cur != fast){
            cur = cur->next;
            fast = fast->next;
        }
        return cur;
    }
};