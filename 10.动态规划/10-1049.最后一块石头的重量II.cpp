// https://leetcode.cn/problems/last-stone-weight-ii/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> dp(15001, 0);
        int sum = 0;
        for(int i = 0; i < stones.size(); i++){
            sum += stones[i];
        }
        int target = sum / 2;
        for(int i = 0; i < stones.size(); i++){
            for(int j = target; j >= stones[i]; j--){
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[target] - dp[target];
    }
};

// 二维数组
class Solution1 {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<vector<int>> dp(stones.size(), vector<int>(15001, 0));
        int sum = 0;
        for(int i = 0; i < stones.size(); i++){
            sum += stones[i];
        }

        // 初始化
        for (int j = stones[0]; j <= 15000; j++) {
            dp[0][j] = stones[0];
        }
        int target = sum / 2;
        for(int i = 1; i < stones.size(); i++){
            for(int j = 0; j <= 15000; j++){
                if (j < stones[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[stones.size() - 1][target] - dp[stones.size() - 1][target];
    }
};

int main()
{
    Solution1 s;
    vector<int> v{2,7,4,1,8,1};
    s.lastStoneWeightII(v);
}