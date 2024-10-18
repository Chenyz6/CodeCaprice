// https://leetcode.cn/problems/two-sum/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> m;
		for (int i = 0; i < nums.size(); i++) {
			auto it = m.find(target - nums[i]);
			if (it != m.end()) {
				return {it->second, i};
			}
			else {
				m.insert(pair<int, int>(nums[i], i));
			}
		}
		return {};
	}
};

int main()
{
	system("pause");
	return 0;
}