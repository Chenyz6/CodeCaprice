// https://leetcode.cn/problems/permutations-ii/description/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;
            if(i > 0 && used[i - 1] && nums[i - 1] == nums[i]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return result;
    }
};
