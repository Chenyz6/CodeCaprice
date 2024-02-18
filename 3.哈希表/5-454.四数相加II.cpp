// https://leetcode.cn/problems/4sum-ii/description/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		unordered_map<int, int> m;
		int count = 0;
		for (int a : nums1) {
			for (int b : nums2){
				m[a + b]++;
			}
		}
		for (int c : nums3) {
			for (int d : nums4) {
				if (m.find(0 - (c + d)) != m.end()) {
					count += m.find(0 - (c + d))->second;    // (c + d) 一定要加括号  不然负数会影响结果
				}
			}
		}
		return count;
	}
};

int main()
{
	system("pause");
	return 0;
}