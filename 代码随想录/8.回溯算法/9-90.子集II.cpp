// https://leetcode.cn/problems/subsets-ii/description/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path = {};
    void backtracking(vector<int>& nums, int startIndex){
        if(startIndex == nums.size()) return;
        for(int i = startIndex; i < nums.size(); i++){
            if(i > startIndex && nums[i] == nums[i - 1]) continue;  // 注意这里使用i > startIndex
            path.push_back(nums[i]);
            result.push_back(path);
            backtracking(nums, i + 1);
            path.pop_back(); 
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.push_back(path);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }
};