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

#include <vector>
class Solution {
public:
    int jumpFloor(int number) {
        vector<int> dp(number + 1);
        dp[1] = 1; dp[2] = 2;
        for(int i = 3; i <= number; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        } 
        return dp[number];
    }
};

int main()
{
    return 0;
}