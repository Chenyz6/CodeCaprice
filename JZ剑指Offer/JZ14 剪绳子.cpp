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

// 动态规划
class Solution {
public:
    int cutRope(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1; dp[2] = 2; dp[3] = 3; dp[4] = 4;
        if(n <= 3) return n - 1;
        //遍历后续每一个长度
        for(int i = 5; i <= n; i++)
            //可以被分成两份
            for(int j = 1; j < i; j++)
                //取最大值
                dp[i] = max(dp[i], dp[j]* dp[i - j]);
        return dp[n];
    }
};

// 贪心  n >= 5  多去减3
class Solution1 {
public:
    int cutRope(int number) {
        //不超过3直接计算
        if(number <= 3) 
            return number - 1;
        int res = 1;
        while(number > 4){
            //连续乘3
            res *= 3; 
            number -= 3; 
        }
        return res * number;
    }
};


int main()
{
    return 0;
}