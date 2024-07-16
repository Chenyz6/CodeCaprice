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
    int jumpFloorII(int number) {
        vector<int> dp(number + 1);
        //初始化前面两个
        dp[0] = 1; 
        dp[1] = 1;
        //依次乘2
        for(int i = 2; i <= number; i++) 
            dp[i] = 2 * dp[i - 1];
        return dp[number];
    }
};


// 老方法
class Solution {
public:
    int jumpFloorII(int number) {
        vector<int> dp(number + 1, 0);
        dp[0] = 1;
        dp[1] = 1; dp[2] = 2;
        dp[3] = 4;
        for(int i = 4; i <= number; i++){
            for(int j = i - 1; j >= 0; j--){
                dp[i] += dp[j];
            }
        }
        return dp[number];
    }
};

int main()
{
    return 0;
}