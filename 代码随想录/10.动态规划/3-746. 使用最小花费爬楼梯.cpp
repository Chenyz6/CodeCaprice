// https://leetcode.cn/problems/min-cost-climbing-stairs/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 1) return cost[0];
        if(cost.size() == 2) {
            if(cost[0] >= cost[1]) return cost[1];
            else return cost[0];
        }
        vector <int> dp(cost.size());
        dp[0] = cost[0];
        if(cost[0] + cost[1] <= cost[1]) dp[1] = cost[0] + cost[1];
        else dp[1] = cost[1];
        for(int i = 2; i < cost.size(); i++){
            int lastLastCost = dp[i - 2] + cost[i];
            int lastCost = dp[i -1] + cost[i];
            if(lastCost <= lastLastCost) dp[i] = lastCost;
            else dp[i] = lastLastCost;
        } 
        if(dp[cost.size() - 1] <= dp[cost.size() - 2]) return dp[cost.size() - 1];
        else return dp[cost.size() - 2];
    }
};

// 官方题解
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1);
        dp[0] = 0; // 默认第一步都是不花费体力的
        dp[1] = 0;
        for (int i = 2; i <= cost.size(); i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[cost.size()];
    }
};

int main()
{
    Solution s;
    vector<int> vec{1,0,0,0};
    s.minCostClimbingStairs(vec);
}