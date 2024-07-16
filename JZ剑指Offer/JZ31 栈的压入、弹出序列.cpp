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
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int n = pushV.size();
        //辅助栈
        stack<int> s;
        //遍历入栈的下标
        int j = 0;
        //遍历出栈的数组
        for(int i = 0; i < n; i++){
            //入栈：栈为空或者栈顶不等于出栈数组
            while(j < n && (s.empty() || s.top() != popV[i])){
                s.push(pushV[j]);
                j++;
            }
            //栈顶等于出栈数组
            if(s.top() == popV[i])
                s.pop();
            //不匹配序列
            else
                return false;
        }
        return true;
    }
};


int main()
{
    return 0;
}