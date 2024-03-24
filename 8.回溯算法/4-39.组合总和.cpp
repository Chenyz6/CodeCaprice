// https://leetcode.cn/problems/combination-sum/description/
#include <iostream>
#include <vector>
using namespace std;


class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;    
public:
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex){
        if(target == sum){
            result.push_back(path);
            return;
        }else if(sum > target){
            return;
        }
        for(int i = startIndex; i < candidates.size(); i++){
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, sum , i);  // 注意这里 是可以重复选取
            path.pop_back();
            sum -= candidates[i];
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return result;
    }
};