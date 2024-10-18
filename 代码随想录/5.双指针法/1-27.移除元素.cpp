// https://leetcode.cn/problems/remove-element/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val){
                continue;
            }else{
                nums[slow++] = nums[i];
            }
        }
        return slow;
    }
};

int main()
{
    return 0;
}