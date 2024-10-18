// https://leetcode.cn/problems/intersection-of-two-arrays/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> result_set;
		unordered_set<int> nums1_set(nums1.begin(),nums1.end());
		for (int num : nums2)
		{
			if (nums1_set.find(num) != nums1_set.end())
			{
				result_set.insert(num);
			}
		}
		return vector<int>(result_set.begin(), result_set.end());
	}
};

int main()
{
	system("pause");
}
