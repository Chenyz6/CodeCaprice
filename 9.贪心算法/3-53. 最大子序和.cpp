// https://leetcode.cn/problems/maximum-subarray/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class SolutionError {   // 186 / 210 个通过的测试用例
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT32_MIN;
        int result = INT32_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max) max = nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == max){
                int leftTemp = 0;
                for(int j = i; j >= 0; j--){
                    leftTemp += nums[j];
                    if(leftTemp >= result) result = leftTemp;
                }
                int rightTemp = 0;
                for(int j = i; j < nums.size(); j++){
                    rightTemp += nums[j];
                    if(rightTemp >= result) result = rightTemp;
                }
                int temp = nums[i];
                for(int z = 1; ; z++){
                    if(i + z >= nums.size() && i - z < 0) break;
                    if(i + z < nums.size()) temp += nums[i + z];
                    if(i - z >= 0) temp += nums[i - z];
                    if(temp >= result) result = temp;
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result) { // 取区间累计的最大值（相当于不断确定最大子序终止位置）
                result = count;
            }
            if (count <= 0) count = 0; // 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
        }
        return result;
    }
};



int main()
{
    // Solution s;
    // vector<int> nums{-1,1,2,1};
    // cout << s.maxSubArray(nums) << endl;
}