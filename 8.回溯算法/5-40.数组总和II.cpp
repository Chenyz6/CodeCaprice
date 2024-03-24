// https://leetcode.cn/problems/combination-sum-ii/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
public:
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex){
        if(sum == target){
            result.push_back(path);
            return;
        }else if(sum > target) return;

        for(int i = startIndex; i < candidates.size(); i++){
            if (i > startIndex && candidates[i] == candidates[i - 1]) {
                continue;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, sum, i + 1);
            path.pop_back();
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
};


int main()
{
    Solution s;
    vector<int> v {2,5,1,2,5};
    s.combinationSum2(v, 5);
}