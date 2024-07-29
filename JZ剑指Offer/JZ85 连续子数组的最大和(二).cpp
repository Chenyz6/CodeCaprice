#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <unordered_map>
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
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        vector<int> res;
        //记录到下标i为止的最大连续子数组和
        vector<int> dp(array.size(), 0);
        dp[0] = array[0];
        int maxsum = dp[0];
        //滑动区间
        int left = 0, right = 0;
        //记录最长的区间
        int resl = 0, resr = 0;
        for (int i = 1; i < array.size(); i++) {
            right++;
            //状态转移：连续子数组和最大值
            dp[i] = max(dp[i - 1] + array[i], array[i]);
            //区间新起点
            if (dp[i - 1] + array[i] < array[i])
                left = right;
            //更新最大值
            if (dp[i] > maxsum || dp[i] == maxsum &&
                    (right - left + 1) > (resr - resl + 1)) {
                maxsum = dp[i];
                resl = left;
                resr = right;
            }
        }
        //取数组
        for (int i = resl; i <= resr; i++)
            res.push_back(array[i]);
        return res;
    }
};


int main()
{
    return 0;
}