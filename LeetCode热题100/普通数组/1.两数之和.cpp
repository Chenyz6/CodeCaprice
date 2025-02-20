// https://leetcode.cn/problems/two-sum/description/?envType=study-plan-v2&envId=top-100-liked
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            auto it = map.find(target - nums[i]);
            if(it != map.end()){
                return {i, it->second};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};