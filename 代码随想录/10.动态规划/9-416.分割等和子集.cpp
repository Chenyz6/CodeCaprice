// https://leetcode.cn/problems/partition-equal-subset-sum/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<int> dp(10001, 0);
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if (sum % 2 == 1) return false;
        int target = sum / 2;
        for(int i = 0; i < nums.size(); i++){  // 物品
            for(int j = target; j >= nums[i]; j--){ // 背包
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
            for(int i = 0; i <= target; i++){
                cout << dp[i] << " ";
            }cout << endl;
        }
        if (dp[target] == target) return true;
        return false;
    }
};

int main()
{
    Solution s;
    vector <int> v{1,5,11,5};
    s.canPartition(v);
}