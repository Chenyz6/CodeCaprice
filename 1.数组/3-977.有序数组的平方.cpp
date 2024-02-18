// https://leetcode.cn/problems/squares-of-a-sorted-array/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		vector<int> result(nums.size(), -1);
		int k = right;
		while (k >= 0){
			if (nums[left] * nums[left] >= nums[right] * nums[right]) {
				result[k--] = nums[left] * nums[left];
				left++;
			}
			else {
				result[k--] = nums[right] * nums[right];
				right--;
			}
		}
		return result;
	}
};

int main()
{
	vector<int> v = { -4,-1,0,3,10 };
	Solution s;
	vector<int> q = s.sortedSquares(v);
	system("pause");
}