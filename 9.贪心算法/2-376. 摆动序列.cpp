// https://leetcode.cn/problems/wiggle-subsequence/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int result = 1;
        int curDiff = 0;
        int preDiff = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            curDiff = nums[i + 1] - nums[i];
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
                preDiff = curDiff; // 注意这里，只在摆动变化的时候更新prediff
            }
        }
        return result;
    }
};