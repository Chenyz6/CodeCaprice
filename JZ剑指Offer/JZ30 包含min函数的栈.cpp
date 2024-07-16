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
private:
    stack<int> data_st;
    stack<int> min_st;
public:
    void push(int value) {
        data_st.push(value);
        if(min_st.empty()) min_st.push(value);
        else{
            if(value <= min_st.top()){
                min_st.push(value);
            }
        }
    }
    void pop() {
        if(data_st.top() == min_st.top()){
            min_st.pop();
        }
        data_st.pop();
    }
    int top() {
        return data_st.top();
    }
    int min() {
        return min_st.top();
    }
};

int main()
{
    return 0;
}