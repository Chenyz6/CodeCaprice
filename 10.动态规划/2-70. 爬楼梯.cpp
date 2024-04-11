// https://leetcode.cn/problems/climbing-stairs/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        vector <int> dp(n);
        dp[1] = 1; dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// 优化空间复杂度的版本
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return n;
        int dp[3];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            int sum = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        return dp[2];
    }
};