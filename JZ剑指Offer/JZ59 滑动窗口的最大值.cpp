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
    vector<int> maxInWindows(vector<int>& num, int size) {
        if(num.empty() || size > num.size() || size == 0) return {};
        vector<int> result;
        deque<int> deq;
        for(int i = 0; i < size; i++){
            while(!deq.empty() && num[i] >= num[deq.back()]){
                deq.pop_back();
            }
            deq.push_back(i);
        }
        for(int i = size; i < num.size(); i++){
            result.push_back(num[deq.front()]);
            while(!deq.empty() && num[i] >= num[deq.back()]){
                deq.pop_back();
            }
            if(!deq.empty() && deq.front() < (i - size + 1)){
                deq.pop_front();
            }
            deq.push_back(i);
        }
        result.push_back(num[deq.front()]);
        return result;
    }
};

int main()
{
    return 0;
}