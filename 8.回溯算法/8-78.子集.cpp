// https://leetcode.cn/problems/subsets/description/

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
        for (int i = startIndex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            result.push_back(path);
            backtracking(nums, i + 1);
            path.pop_back();
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        result.push_back(path);
        backtracking(nums, 0);
        return result;
    }
};