#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
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
    int Fibonacci(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1; dp[2] = 1;
        if(n <= 2) return 1;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int Fibonacci1(int n) { // 优化
        // write code here
        int a = 1, b = 1, c;
        for (int i = 1; i < n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return a;
    }
};

int main()
{
    return 0;
}