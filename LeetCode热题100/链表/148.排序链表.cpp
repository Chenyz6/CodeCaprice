// https://leetcode.cn/problems/sort-list/?envType=study-plan-v2&envId=top-100-liked


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 自顶向下的方法  归并排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }
    ListNode* sortList(ListNode* head, ListNode* tail){
        if(head == nullptr) return nullptr;
        if(head->next == tail){
            head->next = nullptr;
            return head;
        }
        ListNode* slow = head, *fast = head;
        while(fast != tail){
            slow = slow->next;
            fast = fast->next;
            if(fast != tail){
                fast = fast->next;
            }
        }
        ListNode* mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));  // 注意尾部
    }

    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* head = new ListNode;
        ListNode* cur1 = head1, *cur2 = head2, *cur = head;
        while(cur1 != nullptr && cur2 != nullptr){
            if(cur1->val <= cur2->val){
                cur->next = cur1;
                cur1 = cur1->next;
            }else{
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
        }
        if(cur1 != nullptr){
            cur->next = cur1;
        }
        if(cur2 != nullptr){
            cur->next = cur2;
        }
        return head->next;
    }
};