#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(!stack2.empty()){
            int result = stack2.top();
            stack2.pop();
            return result;
        }else{
            while (!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
            int result = stack2.top();
            stack2.pop();
            return result;
        }
    }

private:
    stack<int> stack1; // 进
    stack<int> stack2; // 出
};

int main()
{
    return 0;
}