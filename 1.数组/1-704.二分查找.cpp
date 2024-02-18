// https://leetcode.cn/problems/binary-search/
#include<iostream>
#include<vector>
using namespace std;

// ×ó±ÕÓÒ±Õ
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right)
		{
			int mid = left + ((right - left) >> 1);
			if (nums[mid] == target) return mid;
			else if (nums[mid] > target) right = mid - 1;
			else if (nums[mid] < target) left = mid + 1;
		}
		return -1;
	}
};

// ×ó±ÕÓÒ¿ª
class Solution2 {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size();
		while (left < right)
		{
			int mid = left + ((right - left) >> 1);
			if (nums[mid] == target) return mid;
			else if (nums[mid] > target) right = mid;
			else if (nums[mid] < target) left = mid + 1;
		}
		return -1;
	}
};


int main()
{
	vector<int> v = { 1,5,9,23,56,78,456,888 };
	Solution s;
	cout << s.search(v, 456);
	system("pause");
}