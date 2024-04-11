// https://leetcode.cn/problems/non-decreasing-subsequences/description/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex){
        if(path.size() >= 2){
            result.push_back(path);
        }
        if(startIndex == nums.size()) return;
        for(int i = startIndex; i < nums.size(); i++){
            if(i > startIndex) {
                if(nums[i] == nums[i - 1]) {
                    TiaoChu:continue;
                }
                    for(int j = startIndex; j < i; j++){
                        if(nums[i] == nums[j]) goto TiaoChu;
                    }                
            }

            if(path.size() > 0) {
                if(nums[i] >= path.back()){
                    path.push_back(nums[i]);
                }else{
                    continue;
                }
            }else{
                path.push_back(nums[i]);
            }
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};


int main()
{
    Solution s;vector<int> ss {1,2,3,4,5,6,7,8,9,10,1,1,1,1,1};
    vector<vector<int>> result = s.findSubsequences(ss);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j ++){
            cout << result[i][j] << ",";
        }
        cout << endl;
    }
    cout << result.size() << "-------------";
}