#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        if(head == nullptr) return {};
        int strlen = 0;
        ListNode* cur = head;
        while (cur){
            strlen++;
            cur = cur->next;
        }
        vector<int> result;
        cur = head;
        result.resize(strlen);
        for(int i = strlen - 1; i >= 0; i--){
            result[i] = cur->val;
            cur = cur->next;
        }
        return result;
    }
};

int main()
{
    return 0;
}